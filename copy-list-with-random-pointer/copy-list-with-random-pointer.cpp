/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head ==  nullptr) return nullptr;
        unordered_map<Node*,Node*> vtable{};
        Node* newHead = new Node(head->val);
        vtable.insert(make_pair(head,newHead));
        if (head->random != nullptr){
            if (head->random == head){
                newHead->random = newHead;
            }else{
                newHead->random = new Node(head->random->val);
                vtable.insert(make_pair(head->random,newHead->random));
            }

        }
        head = head->next;
        Node* end = newHead;
        
        while(head != nullptr){
            auto ite = vtable.find(head);
            if (ite != vtable.end()) end->next = ite->second;
            else{
                end->next = new Node(head->val);
                vtable.insert(make_pair(head,end->next));
            }

            if (head->random != nullptr){
                ite = vtable.find(head->random);
                if (ite != vtable.end()){
                    end->next->random = ite->second;
                }else{
                    end->next->random = new Node(head->random->val);
                    vtable.insert(make_pair(head->random,end->next->random));
                }
            }
            end = end->next;
            head = head->next;
        }
        return newHead;
    }
};