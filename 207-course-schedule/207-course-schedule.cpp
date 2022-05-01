class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prer) {
        unordered_map<int,vector<int>> pre{};
        for(const auto& v: prer){
            pre[v.front()].push_back(v.back());
        }
        unordered_set<int> have{};
        unordered_set<int> visited{};
        for(int i = 0; i < numCourses; i++){
            if (have.count(i) != 1){
                if (!try_course(i,have,pre, visited)) return false;
            }
        }
        return true;
    }
    bool try_course(int i, unordered_set<int>& have, const unordered_map<int,vector<int>>& pre, unordered_set<int>& visited){
        if (have.count(i) == 1) return true;
        if (pre.count(i) == 0){
            have.insert(i);
            return true;
        }
        if (visited.count(i) == 1) return false;
        visited.insert(i);
        for(const auto& e: pre.find(i)->second){
            if (!try_course(e,have,pre, visited)) return false;
        }
        //visited.erase(i);
        have.insert(i);
        return true;
    }
};