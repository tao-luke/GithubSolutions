class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int counter = 0;
        int forward = size-1;
        while(true){
            if (forward >0){
                swap(s[counter], s[counter+forward]);
                counter++;
                forward = forward-2;
            }else{
                break;
            }
            
        }
    }
};