// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    enum where{here, goLeft, goRight};
    where isfirstBad(int n){
        if (n ==0 && isBadVersion(0)){
            return where::here;
        }
        if (isBadVersion(n)){
            if (!(isBadVersion(n-1))) return where::here;
            return where::goLeft;
        }
        return where::goRight;
        
    }
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l < r){
            int m = l+(r-l)/2;
            where tmp = isfirstBad(m);
            if (tmp == where::here){
                return m;
            }else if (tmp == where::goLeft){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};