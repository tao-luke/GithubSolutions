class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      vector<map<string, int>> buc(26, map<string, int>{});
      int result = 0;
      for(const auto& str: words){
        buc[str.front()-'a'][str]++;
      }
      for(const auto&c:s){
        map<string,int> copy = buc[c-'a'];
        buc[c-'a'].clear();
        for(const auto&p: copy){
          if (p.first.size() == 1){
            result+=p.second;
          }else{
             buc[p.first[1]-'a'][p.first.substr(1)]+=p.second;
          }
        }
      }
      return result;
    }
};