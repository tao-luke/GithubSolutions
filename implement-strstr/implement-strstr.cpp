class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() && needle.empty()) return 0;
        vector<int> l(26,-1);
        int nsize = needle.size();
        int hsize = haystack.size();
        for(int i = 0; i < nsize;i++){
            l[needle[i]-97] = i;
        }
        int i = nsize-1; //for haystack
        int j = nsize-1; //for needle
        while(i < hsize && j >= 0){
            cout << i << " " << j << endl;
            if (needle[j] == haystack[i]){
                i--;
                j--;
            }else{
                i = i+ (nsize-1) - min(j-1,l[haystack[i]-97]);
                j = nsize-1;
            }
        }
        if (j < 0) return i+1;
        return -1;
    }
};