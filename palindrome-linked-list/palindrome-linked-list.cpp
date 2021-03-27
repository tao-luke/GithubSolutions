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
    int getSize(ListNode* head){
        int counter = 0;
        while(head != nullptr){
            head = head->next;
            counter++;
        }
        return counter;
    }
    bool isPalindrome(ListNode* current) {
        if ((current == nullptr) || (current->next == nullptr)) return true; 
        int size = getSize(current);
        int reads = (size/2);
        ListNode* bef = nullptr;
        ListNode* tmp = nullptr;
        //fip the first half
        while(reads > 0){
            tmp = current->next;
            current->next = bef;
            bef = current;
            current = tmp;
            reads--;
        }
        if ((size)%2 != 0){
            current = current->next;
        }
        while(current != nullptr){
            if (current->val != bef->val) return false;
            current = current->next;
            bef = bef->next;
        }
        return true;
    }
};