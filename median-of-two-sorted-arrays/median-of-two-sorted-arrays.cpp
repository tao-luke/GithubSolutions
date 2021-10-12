class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //treat the 2 arrs as one
        int result = 0;
        
        unsigned short size1 = nums1.size();
        unsigned short size2 = nums2.size();
        
        unsigned short targetI = (size1+size2-1)/2;
        unsigned short currentI = 0;
        
        auto ite1 = nums1.begin();
        auto ite2 = nums2.begin();
        
        while(true){
            auto tmp = ite1;
            if (ite1 == nums1.end() or (ite2 != nums2.end() and *ite2 < *ite1)){
                tmp = ite2;
                ite2++;
            }else{
                ite1++;
            }
            // tmp is the current want, and ite1 and ite2 are moved on to NEXT
            if (currentI == targetI){
                if ((size1+size2)%2 != 0) return *tmp;
                
                // get next good and return avg
                return (ite2 == nums2.end() or (ite1 != nums1.end() and *ite1 < *ite2)) ? (*tmp+*ite1)/(double)2 : (*tmp+ *ite2)/(double)2;
            }
            currentI++;
            
        }
    }
};