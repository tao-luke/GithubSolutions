class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int stacker = 1;
        while(x != 0){
            int dig = x%10;
            cout << dig <<endl;
            x /= 10;
            if ((result > INT_MAX/10) || ((result == INT_MAX) && (dig > 7))) return 0;
            if ((result < INT_MIN/10) ||((result == INT_MIN) && (dig < -8))) return 0;
            result = result*10 + dig;
        }
        return result;
    }
};