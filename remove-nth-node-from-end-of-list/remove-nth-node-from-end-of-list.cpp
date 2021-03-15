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
    void getSize(ListNode* node, int& counter){
        if (node == nullptr) return;
        counter++;
        getSize(node->next,counter);
    }
    ListNode* helper(ListNode* head, int& counter){
        if (counter == 1){
            head->next = head->next->next;
            return head;
        }else{
            counter--;
            helper(head->next, counter);
        }
        return nullptr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        getSize(head,size);
        int target = size - n;
        if (target == 0){
            return head->next;
        }
        helper(head, target);
        return head;
    }
};