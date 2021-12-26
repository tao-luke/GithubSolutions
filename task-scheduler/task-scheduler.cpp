class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // keep a map of char->int where int represents the num of char tasks.
        // while map isnt empty, 
        //         check the size of the map.
        //          if size >= n+1
        //              take 1 off of n+1 random thingy, time+=(n+1)
        //          else take size thingy, each --, and time+=(n+1)
        // E F G B C D
        //n + 26*
        
        if (n == 0)  return tasks.size();
        vector<pair<char,int>> store(26,make_pair('A', 0));
        for(const auto& c: tasks) {
            store[c- 'A'].first = c;
            store[c- 'A'].second++;
        }

        auto comp = [](const pair<char,int>& a, const pair<char,int>& b) {
            return a.second > b.second;
        };
        sort(store.begin(), store.end(), comp);
        
        int ans = 0;
        while(store.front().second!= 0) {
            int tmp = 0;
            for(int i=0; i <=min(25,n);i++){
                if (store[i].second == 0) break;
                store[i].second--;
                tmp++;
            }
            sort(store.begin(), store.end(), comp);
            if (store.front().second == 0) ans+=tmp;
            else ans+=(n+1);
        }
        return ans;
    }
};