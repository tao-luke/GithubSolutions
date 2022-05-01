class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> have{};
        //initialize have
        for(const auto& s: supplies){
            have.insert(s);
        }
        vector<string> result{};
        unordered_map<string, vector<string>> recip{};
        //initialize receipes
        for(int i = 0; i < recipes.size();i++){
            recip[recipes[i]] = ingredients[i];
        }
        unordered_set<string> visited{};
        for(int i = 0; i < recipes.size();i++){
            if (have.count(recipes[i]) == 1 || try_make(recipes[i], have,recip, visited)){
                result.push_back(recipes[i]);
            }
        }
        return result;
    }
    bool try_make(string s, unordered_set<string>& have, const unordered_map<string, vector<string>>& recip, unordered_set<string>& visited){
        if (have.count(s) == 1) return true;
        if (recip.count(s) == 0) return false; //not a material we have
        if (visited.count(s) == 1) return false; //cycle
        visited.insert(s);
        for(const auto& ss: recip.find(s)->second){
            if (!try_make(ss, have,recip, visited)) return false;
        }
        visited.erase(s);
        have.insert(s);
        return true;
    }
};