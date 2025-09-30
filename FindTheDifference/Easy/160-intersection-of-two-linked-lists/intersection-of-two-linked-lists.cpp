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
        ListNode *startA=headA;
        ListNode *startB=headB;
        while(startA!=startB){
           startA = (startA== NULL) ? headB : startA->next;
           startB = (startB == NULL) ? headA : startB->next;
        }
           return startA;
    }
};