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
    void deleteNode(ListNode* node) {
        ListNode* cur;
        while(node->next != nullptr){
            node->val = (node->next)->val;
            cur = node;
            node = node->next;
       }
        cur->next = nullptr;
    }
};