class Solution {
public:
    int parent(int i){
        return floor((i-1)/2);
    }
    int leftChild(int i){
        return 2*i+1;
    }
    int rightChild(int i){
        return 2*i+2;
    }
    void fixDown(vector<int>&nums,int index, int size){
        while(leftChild(index) < size){
            int next;
            if (rightChild(index) < size && nums[rightChild(index)] >= nums[leftChild(index)]){
                next = rightChild(index);
            }else{
                next = leftChild(index);
            }
            if (nums[index] < nums[next]){
                swap(nums[index],nums[next]);
            }
            index = next;
        }
    }
    int heapify(vector<int>& nums){
        int size = nums.size();
        int previous = 0;
        int counter = 1;
        for(int i = parent(size-1);i>=0;i--){
            fixDown(nums,i,size);
        }
        while(size >0){
            if (counter == 1){
                previous = nums[0];
                counter--;
            }else{
                if (previous != nums[0]){
                    return previous;
                }
                counter = 1;
            }
            swap(nums[size-1],nums[0]);
            size--;
            fixDown(nums,0,size);
        }
        return previous;
    }
    int singleNumber(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        return heapify(nums);
        
    }
};