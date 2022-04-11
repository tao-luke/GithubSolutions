class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& e) {
        unordered_map<int,vector<int>> edges{};
        for(int i = 0; i < e.size();i++){
            edges[e[i][0]].push_back(e[i][1]);
            if (e[i][0] == e[i][1]) return false;
        }
        vector<int> leaf(numCourses, 0);
        vector<int> path(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if (!try_Course(i, edges, leaf, path)) return false;
        }
        return true;
    }
    bool try_Course(int course, unordered_map<int, vector<int>>& edges, vector<int>& leaf, vector<int>& path){
        if (path[course] == 1) return false;
        if (leaf[course] == 1 || edges[course].empty()){
            leaf[course] = 1;
            return true;
        } 
        path[course] = 1;
        for(const auto& need: edges[course]){
            if (!try_Course(need, edges, leaf, path)) return false;
        }
        path[course] = 0;
        leaf[course] = 1;
        return true;
    }
};