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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* odd = head;
        ListNode* odd_head = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        head = even;
        int counter = 1;
        while(head != nullptr){
            head = head->next;
            if (head == nullptr) break;
            if (counter % 2 == 1){
                odd->next = head;
                odd = odd->next;
            }else{
                even->next = head;
                even = even->next;
            }
            counter++;
        }
        odd->next = even_head;
        if (even != nullptr)even->next = nullptr;
        return odd_head;
    }
};