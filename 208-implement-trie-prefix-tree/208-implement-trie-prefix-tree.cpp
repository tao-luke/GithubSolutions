class Trie {
    class Node{
        public:
        char c;
        unordered_map<char, Node*> child{};
        bool is_end = false;
        Node(char c):c{c}{
        }
        ~Node(){
            for(const auto& p: child){
                delete p.second;
            }
        }
    };
    
    Node* root;
public:
    Trie() {
        root = new Node(0);
    }
    
    void insert(string word) {
        Node* current = root;
        for(const auto& c: word){
            if (current->child.count(c) != 0){
                current = current->child[c];
            }else{
                current->child[c] = new Node(c);
                current = current->child[c];
            }
        }
        current->is_end = true;
    }
    
    bool search(string word) {
        Node* current = root;
        for(const auto& c: word){
            if (current->child.count(c) != 0){
                current = current->child[c];
            }else{
                return false;
            }
        }
        return current->is_end;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        for(const auto& c: prefix){
            if (current->child.count(c) != 0){
                current = current->child[c];
            }else{
                return false;
            }
        }
        return true;
    }
    ~Trie(){
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */