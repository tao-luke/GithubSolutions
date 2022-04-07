class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n,-1);
        int ans = n;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if (isConnected[i][j] != 1) continue;
                int l1 = find(parent,i);
                int l2 = find(parent,j);
                if (l1 != l2){
                    ans--;
                    parent[l1] = l2;
                }
            }
        }
        return ans;
    }
    int find(const vector<int>& parent, int i){
        if (parent[i] == -1) return i;
        return find(parent, parent[i]);
    }
};
