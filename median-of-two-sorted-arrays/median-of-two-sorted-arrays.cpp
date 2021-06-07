class Solution {
public:
    bool a_less_b(const vector<int>& nums1, int c1, vector<int>& nums2,int c2){
        if (c1 >= nums1.size()) return false;
        if (c2 >= nums2.size()) return true;
        return nums1[c1] < nums2[c2];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int target1 = max(ceil((nums1.size() + nums2.size()) /(double) 2 )-1,0.0);
        int target2 = (nums1.size() + nums2.size()) / 2;
        int ans = 0;
        int counter1 = 0;
        int counter2 = 0;
        while(true){
            if (a_less_b(nums1,counter1,nums2,counter2)){
                if (counter1 + counter2 == target1){
                    ans = nums1[counter1];
                }
                if (counter1 + counter2 == target2){
                    ans += nums1[counter1];
                    break;
                } 
                counter1++;
            }else{
                if (counter1 + counter2 == target1){
                    ans = nums2[counter2];
                }
                if (counter1 + counter2 == target2){
                    ans += nums2[counter2];
                    break;
                } 
                counter2++;
            }
        }
        return ans/(double) 2;
    }
};