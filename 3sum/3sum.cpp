class Solution {
public:
        void swap(vector<int>& arr, int n1, int n2){
        int tmp = arr[n1];
        arr[n1] = arr[n2];
        arr[n2] = tmp;
    }
int partition(vector<int>& arr, int pIndex, int begin,int end){
    if (end == begin) return begin;
    int i = begin-1,j=end+1,v = arr[pIndex];
    swap(arr,end,pIndex);
    while(true){
        do{
            if (i == end) return end;
            i++;
        }while(arr[i]<= v);
        do{
            j--;
        }while(j >= i && arr[j] >= v );
        if (j <= i){
            swap(arr,i,end);
            return i;
        }else{
            swap(arr,i,j);
        }
    }
}

    void quickSort(vector<int>& arr){
        stack<pair<int,int>> parts{};
        int size = arr.size();
        parts.push(make_pair(0,size-1)); //big range
        int begin = 0, end = 0;
        int pivot = 0, i = 0;
        while(!parts.empty()){
            const pair<int,int> tmp = parts.top();
            parts.pop();
            begin = tmp.first;
            end = tmp.second;
            while (end > begin){
                pivot = floor((end-begin)/2) + begin;
                // cout << "current:" << pivot <<" " <<" " <<  begin << "" <<end<<endl;
                // for(auto i:arr){
                //     cout << i << "  ";
                // }
                i = partition(arr,pivot,begin,end);
                // cout << "correct index is:" << i << endl <<"after:";
                // for(auto i:arr){
                //     cout << i << "  ";
                // }
                // cout << endl;
                if (i - begin < end - i){
                    parts.push(make_pair(i+1,end));
                    end = i-1;
                }else{
                    parts.push(make_pair(begin,i-1));
                    begin = i+1;
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result{};
        quickSort(nums);
        for(int i = 0; i < size;i++){
            unordered_set<int> seen{};
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j < size; j++){
                if (seen.count(-nums[i]-nums[j])){
                    result.push_back({nums[i],nums[j],-nums[i]-nums[j]});
                    while (j+1 < size && nums[j+1] == nums[j])j++;
                }else{
                    seen.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

