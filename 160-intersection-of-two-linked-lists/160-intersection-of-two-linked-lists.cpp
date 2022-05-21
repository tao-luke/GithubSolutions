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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // l1 + inter + l2 , the other travels l2 + inter + l1
        ListNode* p1 = headA; ListNode* p2 = headB;
        int counter = 2;
        while(p1 != nullptr && p2 != nullptr && p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == nullptr && counter > 0){
                p1 = headB;
                counter--;
            }
            if (p2 == nullptr && counter > 0){
                p2 = headA;
                counter--;
            }
        }
        if (p1 == nullptr || p2 == nullptr) return nullptr;
        return p1;
    }
};