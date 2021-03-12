class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto current = digits.rbegin();
        bool carry = true;
        while(current != digits.rend()){
            if (*current == 9){
                *current = 0;
            }else{
                (*current)++;
                carry = false;
                break;
            }
            current++;
        }
        if (carry == false){
            return digits;
        }else{
            digits.push_back(0);
            int index = digits.size() -1;
            while (index >= 0){
                if (index == 0){
                    digits[index] = 1;
                }else{
                    digits[index] = digits[index-1];

                }
                index--;
            }
        }
        return digits;
    }
};