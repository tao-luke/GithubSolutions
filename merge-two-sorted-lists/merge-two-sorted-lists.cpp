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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* start = nullptr;

        if (l1->val > l2->val){
            start = l2;
            l2 = l2->next;
        }else{
            start = l1;
            l1 = l1->next;
        }
        ListNode* end = start;
        while(l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                end->next = l2;
                l2 = l2->next;
            }
            else if (l2 == nullptr){
                end->next = l1;
                l1 = l1->next;
            } 
            else{
                if (l1->val > l2->val){
                    end->next = l2;
                    l2 = l2->next;
                }
                else{
                    end->next = l1;
                    l1 = l1->next;
                } 
            } 
            end = end->next;
        }
        end->next = nullptr;
        return start;
    }
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* tmp = nullptr;
//         ListNode* tmp2 = nullptr;
//         if (l1 == nullptr) return l2;
//         if (l2 == nullptr) return l1;
//         if (l1->val > l2->val){
//             tmp = l1;
//             l1 = l2;
//             l2 = tmp;
//         }
//         //l1's first num is no greater than l2
//         tmp = l1;
//         while((l1->next != nullptr) && (l2 != nullptr)){
//             while (l2->val <= (l1->next)->val){
//                 tmp2 = l2;
//                 l2 = l2->next;
//                 tmp2->next = l1->next;
//                 l1->next = tmp2;
//                 if (l2 == nullptr) break;
//             }
//             l1 = l1->next;
//         }
//         if (l1->next == nullptr){
//             l1->next = l2;
//         }
        
        
//         return tmp;
//     }
};