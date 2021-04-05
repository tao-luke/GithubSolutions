class Solution {
public:
    int parent(int i){
    return (i-1)/2;
}
int leftChild(int i){
    return (2*i)+1;
}
int rightChild(int i){
    return (2*i)+2;
}
void fixdown(string& a, int i, int cap){
    while(leftChild(i) < cap){ //this node is NOT leaf
        if ((rightChild(i) < cap) && (a[rightChild(i)] > a[leftChild(i)])){
            if (a[i] < a[rightChild(i)]){
                swap(a[i],a[rightChild(i)]);
                i = rightChild(i);
            }else{
                break;
            }
        }else if (a[i] < a[leftChild(i)]){
            swap(a[i],a[leftChild(i)]);
            i = leftChild(i);
        }else{
            break;
        }
    }
}

void heapSort(string& a){
    if (a.size() < 2) return;
    
    int size = a.size();
    for(int i = parent(size-1);i >= 0;i--){
        fixdown(a,i,size);
    }
    size--;
    while(size >= 0){
        swap(a[0],a[size]);
        fixdown(a,0,size);
        size--;
    }
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapping{};
        for(auto& word: strs){
            string wordCopy = word;
            heapSort(word);
            auto ite = mapping.find(word);
            if (ite == mapping.end()) mapping.insert(make_pair(word,vector<string>{wordCopy}));
            else ite->second.push_back(wordCopy);
        }
        vector<vector<string>>result{};
        for(auto& m: mapping){
            result.push_back(m.second);
        }
        return result;
    }
};