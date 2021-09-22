class Solution {
public:
    // the idea is just like 2sum but we lock off 1 index at a time.ofc we sort first
    //suppose arr [a,b,c,d,e], we would go through the array with a locked, then b locked, then c and so on. With each time, having the other 2 inedx to the right of the locked one and adjusting as needed. Ex: a locked, j is on b and k is on e, then we calc the sum of a b e, if big, shift ptr to e to d and so on.
    // we get dups however if naively impelent like above, we thus elminate them by each time scoring a j,k that we update j and k to the next diff value. same logic applies to each time we up i, keep upating it till its a diff value.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result{};
        short size = nums.size();
        heapSort(nums);
        //sort(nums.begin(),nums.end());
        for(short i = 0; i <size;i++){
            if (i > 0 && nums[i] == nums[i-1])continue; //dup n1
            short j = i+1;
            short k = size-1;
            while(j < k){
                if (nums[j]+nums[k] == -nums[i]){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    while(j < k && nums[k] == nums[k-1])k--; //dup3
                    while(j < k && nums[j]  == nums[j+1])j++; //dup2
                    k--;j++;
                } 
                else if (nums[j]+nums[k] < -nums[i]){
                    while(j < k && nums[j]  == nums[j+1])j++; //dup2
                    j++;
                }
                else{
                    while(j < k && nums[k] == nums[k-1])k--; //dup3
                    k--;
                }
            }
        }
        return result;
    }
    void heapSort(vector<int>& nums){
        heapify(nums);
        for(short i = nums.size()-1;i >=0;i--){
            swap(nums[0],nums[i]);
            fix_down(nums,0,i);
        }
    }
    short parent(short i){
        return (i-1)/2;
    }
    short leftChild(short i){
        return 2*i+1;
    }
    short rightChild(short i){
        return 2*i+2;
    }
    void fix_down(vector<int>& nums, short i,short size){
        while(leftChild(i) < size){//while i is not last layer
            if (rightChild(i) < size && nums[rightChild(i)] > nums[leftChild(i)]){
                //if yes right child, and right > left
                if (nums[i] < nums[rightChild(i)]){
                    swap(nums[i],nums[rightChild(i)]);
                    i = rightChild(i);
                }else return;
            }
            else if (nums[i] < nums[leftChild(i)]){
                swap(nums[i],nums[leftChild(i)]);
                i = leftChild(i);
            }else return;
        }
    }
    void heapify(vector<int>& nums){
        short size = nums.size();
        for(short i = parent(size-1);i >=0;i--){
            fix_down(nums,i,size);
        }
    }
};