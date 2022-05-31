class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        if (b != 0){
            return (getSum(a^b, (a&b) << 1));
        }
        return (int)a;
    }
};


