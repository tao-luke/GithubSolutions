class Solution {
    class Node{
        int val;
        Node* next;
        Node():val(0),next(nullptr){
        }
        Node(int val, Node* next):val(val),next(next){}
    };
public:
    int partition(vector<int>& nums,int p,int left, int right){
    if (left >= right) return -1;
    int l = left-1;
    int r = right;
    swap(nums[p],nums[right]);
    while(true){
        do{
            l++;
        }while(l < right && nums[l] <= nums[right]);
        do{
            r--;
        }while(r > l && nums[r] >= nums[right]);
        if (r <= l){
            swap(nums[l],nums[right]);
            return l;
        }
        swap(nums[l],nums[r]);
    }

}
int getPivot(const vector<int>& nums,int l, int r){
    if ( (r-l+1) >= 3){
        int mid = l + floor((r-l)/2);
        if (nums[l] <= nums[mid] && nums[mid] <= nums[r]){
            return mid;
        }else if (nums[mid] <= nums[l] && nums[l] <= nums[r]){
            return l;
        }else{
            return r;
        }
    }else{
        return l;
    }
}
void quickSort(vector<int>& nums){
    stack<pair<int,int>> coord{};
    coord.push(make_pair(0,nums.size()-1));
    while(!(coord.empty())){
        int l = coord.top().first;
        int r = coord.top().second;
        int tmp = partition(nums,getPivot(nums,l,r),l,r);
        coord.pop();
        if (tmp != -1){
            coord.push(make_pair(l,tmp-1));
            coord.push(make_pair(tmp+1,r));
        }
    }
}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(const auto & e: nums2){
            nums1[m++] = e;
        }
        quickSort(nums1);
    }
};