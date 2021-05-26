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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* oddStart = head;
        ListNode* evenStart = head->next;
        ListNode* oddNext = oddStart;
        ListNode* evenNext = evenStart;
        ListNode* current = head->next;
        
        int counter = 2;
        while(current != nullptr){
            if (counter <=2){
                counter++;
                current = current->next;
                continue;
            } 
            if (counter %2 == 0){
                evenNext->next = current;
                evenNext = current;
            }else{
                oddNext->next = current;
                oddNext = current;
            }
            current = current->next;
            counter++;
        }
        evenNext->next = nullptr;
        oddNext->next = evenStart;
        return oddStart;
    }
};