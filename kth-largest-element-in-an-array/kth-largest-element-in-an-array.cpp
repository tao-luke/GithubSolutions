class Solution {
public:
    int partition(vector<int>& arr,int start, int end, int pivot){
        end--;
        swap(arr[pivot],arr[end]);
        pivot = end;
        while (true){
            do{
                start++;
            }while(start < end && arr[start] > arr[pivot]);
            do{
                end--;
            }while(end > start && arr[end] <= arr[pivot]);
            if (start >= end){
                swap(arr[start],arr[pivot]);
                return start;
            }
            swap(arr[start],arr[end]);
        }
    }
    int getPivot(const vector<int>& nums, int left, int right){
        if (right - left -1 >= 3){
            if (nums[left+1] >= nums[left + (right-left -1)/2] >= nums[right-1]) return left+1 + (right-left -1)/2;
            if (nums[left+1] >= nums[right-1] >= nums[left + (right-left -1)/2]) return right-1;
            return left+1;
        }else return right-1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = -1;
        int right = nums.size();
        k--;
        while (true){
            int tmp = partition(nums,left,right,getPivot(nums,left,right));
            if (tmp == k) return nums[tmp];
            else if (tmp > k) right = tmp;
            else left = tmp;
        }
        
    }
};