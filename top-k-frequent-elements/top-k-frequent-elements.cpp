class Solution {
public:
    int partition(vector<pair<int,int>>& arr,int start,int end, int pivot){
        if (end - start < 2) return end-1;
        swap(arr[pivot],arr[end-1]); 
        //prep ptr
        start--;
        end--;
        pivot = end;
        while(true){
            do{
                start++;
            }while(start < end && arr[start].second >= arr[pivot].second);

            do{
                end--;
            }while(end > start && arr[end].second < arr[pivot].second);
            if (start >= end){
                swap(arr[start],arr[pivot]);
                return start;
            }
            swap(arr[start],arr[end]);
        }
    }
    void partitionAtIndex(vector<pair<int,int>>& arr, const int& k){
        int left = 0;
        int right = arr.size();
        while (true){
            int tmp = partition(arr,left,right,right-1);
            if (tmp == k) return;
            else if (tmp > k) right = tmp;
            else left = tmp+1;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap{};
        for(const auto& n: nums){
            auto ite = freqMap.find(n);
            if (ite == freqMap.end()){
                freqMap.insert(make_pair(n,1));
            }else{
                ite->second++;
            }
        }
        vector<pair<int,int>> freqArr{};
        for(const pair<int,int>& p: freqMap){
            freqArr.push_back(p);
        }
        freqMap.clear(); //clear up unused
        if (k != freqArr.size()){
            partitionAtIndex(freqArr,k-1); //partiton at index k
        }
        vector<int> result{}; //init result
        for(int i = 0; i <k ;i++){ //save result
            result.push_back(freqArr[i].first);
        }
        return result;
    }
};