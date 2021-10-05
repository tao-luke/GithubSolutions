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
    Node* firstPass(Node* head){
        Node* front = head;
        while(head != nullptr){
            Node* tmp = new Node(head->val);
            tmp->next = head->next;
            head->next = tmp;
            head = head->next->next;
        }
        return front;
    }
    Node* secondPass(Node* head){
        Node* front = head;
        while(head != nullptr){
            Node* tmp = head->next;
            if (head->random){
                tmp->random = head->random->next;
            }
            head = head->next->next;
        }
        head = front;
        front = head->next;
        while(head != nullptr){
            Node* tmp = head->next;
            if (tmp->next){
                head->next = tmp->next;
                tmp->next =  head->next->next;
            }else{
                head->next = nullptr;
            }
            head = head->next;
        }
        return front;
    }
    Node* copyRandomList(Node* head) {
        if (!head )return head;
        head = firstPass(head);
        return secondPass(head);
    }
};