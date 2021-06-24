class Solution {
public:
    /* Idea 1: naive. I essentially tried to find exactly the 3 numbers in the triplet succession. However, this is impossible to do in the runtime and space need. the better way to do this is almost like a 3 segment divide and conquere. 
        Soln: the assumption to need is simple, suppose spots I J K as needed in the question, we just need to have I and J exist before K, I exist before J and have an I. This means that when a new number N is approached. we compare it sequently to I , J and K. if its < I, replace I, if < J then replace J, if < k return true!!!!! the essence is jthat we JUST need to know 2 numbers existed before the third and that third is > the first two.
    
    */
    bool increasingTriplet(const vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return false;
        int i = 0;
        int j = -1;
        for(int index = 1; index < size;index++){
            if (nums[index] <= nums[i]){
                i = index;
            }else if (j == -1 || nums[index] <= nums[j]){
                j = index;
            }else return true;
        }
        return false;
    }
};