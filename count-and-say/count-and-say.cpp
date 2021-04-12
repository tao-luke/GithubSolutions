class Solution {
public:
    string speak(string&& n){
        char c = n[0];
        string result{};
        int counter = 0;
        for(const auto& nc:n){
            if (nc == c){
                counter++;
            }else{
                result.append(to_string(counter));
                result.push_back(c);
                c = nc;
                counter = 1;
            }
        }
        result.append(to_string(counter));
        result.push_back(c);
        return result;
    }
    string countAndSay(int n) {
        if (n <= 1) return "1";
        else return speak(countAndSay(n-1));
    }
};