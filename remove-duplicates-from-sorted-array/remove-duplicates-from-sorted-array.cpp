class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size ==0 || size == 1){
            return size;
        }
        //size must be >=2
        int counter = 1;
        int *p1 = nums.data();
        int lastNum = *p1; //set last num as first
        int *p2 = (++p1); //set both p1 to second, p2 to third element
        int *pend = p1+(size-1); //set pend as end ptr(NOT dereferenced)

        while (p2 != pend ){
            if (*p2 > lastNum){
                counter++;
                lastNum = *p2;
                swap(*p2,*p1);
                ++p1;
            }
            ++p2;
        }
        return counter;
    }
};