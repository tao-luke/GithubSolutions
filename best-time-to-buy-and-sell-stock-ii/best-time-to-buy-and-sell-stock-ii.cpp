class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 2){
            if (size == 1){
                return 0;
            }else{
                int tmp = prices[1]-prices[0];
                if (tmp > 0) return tmp;
                return 0;
            }
        }
        //size at least 2
        int * p1 = prices.data();
        int *pend = p1+(size);
        int counter = 0;
        while(p1+1 != pend){
            if (p1[1] > *p1){
                counter+=(p1[1])-(*p1);
            }
            p1++;
        }
        return counter;
    }
};