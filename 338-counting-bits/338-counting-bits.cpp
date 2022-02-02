class Solution {
public:
    vector<int> countBits(int n) {
        //bruh this is dp. theres a pattern. 
        vector<int> result{};
        result.push_back(0);
        int counter = 1;
        for(int i = 1; i <= n; i++){
            if (i == 2 * counter){
                counter = counter * 2;
                result.push_back(result[i-counter] + 1);
            }else{
                result.push_back(result[i-counter] + 1);
            }
        }
        return result;
    }
};