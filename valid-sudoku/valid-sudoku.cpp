class Error{};
class Solution {
public:
    void read(vector<unordered_map<char,pair<int,int>>> & collection,vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_map<char,pair<int,int>> small;
            int x = i%3 * 3;
            int y = i/3 * 3;
            for(int j = 0; j < 9;j++){
                if (board[x+j%3][ y + j/3] != '.'){
                    if (small.count(board[x+j%3][ y + j/3]) != 0){
                        throw Error();
                    }else{
                        small.insert(make_pair(board[x+j%3][y+j/3],make_pair(x+j%3,y+j/3)));
                    }
                }
            }
            collection.push_back(std::move(small));
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,pair<int,int>>> collection{};
        try{
            read(collection,board);
        }catch(...){
            return false;
        }
        
        for(char i = '1'; i <='9';i++){
            unordered_set<char> seenx{};
            unordered_set<char> seeny{};
            for(const auto & e: collection){
                auto tmp = e.find(i);
                if (tmp != e.end()){
                    if (seenx.count((tmp->second).first) != 0){
                        return false;
                    }
                    if (seeny.count((tmp->second).second) != 0){
                        return false;
                    }
                    seenx.insert((tmp->second).first);
                    seeny.insert((tmp->second).second);
                }
            }
        }
        return true;
    }
};