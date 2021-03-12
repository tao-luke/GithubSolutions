/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* current) {
        if (current == nullptr) return current;
        ListNode* next = current->next;
        ListNode* tmp = current;
        current->next = nullptr;
        while(next != nullptr){
            tmp = next->next;
            next->next = current;
            current = next;
            next = tmp;
        }
        return current;
    }
};