/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        if (!(head) || !(head->next)) return false;
        ListNode *fast = head;
        while(fast != nullptr){
            head = head->next;
            fast = fast->next;
            if (fast == nullptr) break;
            fast = fast->next;
            if (fast == head) return true;
        }
        return false;
    }
};