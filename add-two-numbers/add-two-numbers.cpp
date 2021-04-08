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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        bool carry = false;
        ListNode* result = l1;
        int tmp = 0;
        while(!(l1 == nullptr && l2 == nullptr) || carry){
            if (l1 != nullptr && l2 != nullptr && l1->val != -1){ //normal case
                tmp = l1->val + l2->val;
                if (carry) tmp++;
                if (tmp < 10) carry = false;
                else carry = true;
                l1->val = tmp%10;
                if (l1->next == nullptr &&(carry || l2->next != nullptr)) l1->next = new ListNode(-1);
                l1 = l1->next;
                l2 = l2->next;
            }else if (l1->val == -1){
                tmp = 0;
                if (l2 != nullptr){
                    tmp = l2->val;
                    l2 = l2->next;
                }
                if (carry){
                    tmp++;
                }
                if (tmp < 10) carry = false;
                else carry = true;
                l1->val = tmp%10;
                if (l1->next == nullptr &&(carry || l2 != nullptr)) l1->next = new ListNode(-1);
                l1 = l1->next;
            }else{
                if (carry){
                    l1->val++;
                }
                if (l1->val < 10) carry = false;
                else carry = true;
                l1->val = l1->val%10;
                if (l1->next == nullptr && carry){
                    l1->next = new ListNode(-1);
                }
                l1 = l1->next;
            }
        }
        return result;
    }
};