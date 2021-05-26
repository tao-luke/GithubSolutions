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
    int getSize(ListNode* root){
        int counter = 0;
        while(root != nullptr){
            counter++;
            root = root->next;
        }
        return counter;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        int sizeA = getSize(headA);
        int sizeB = getSize(headB);
        int tmp = 0;
        if (sizeA > sizeB){
            tmp = sizeA - sizeB;
            while(tmp != 0){
                headA = headA->next;
                tmp--;
            }
        }else if (sizeB > sizeA){
            tmp = sizeB - sizeA;
            while(tmp != 0){
                headB = headB->next;
                tmp--;
            }
        }
        while(headA != nullptr){
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};