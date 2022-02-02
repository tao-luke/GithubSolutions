class Solution {
public:
    int getSum(unsigned int a, unsigned b) {
        if (b == 0) return a;
        else return getSum((a^b),(a&b)<<1);
    }
};