class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 1;
        int bound = sqrt(2*n);
        for(int i = 2; i <= bound;i++){
            if ((n - i*(i-1)/2) % i == 0) count++;
        }
        return count;
    }
};