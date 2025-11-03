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
       ListNode*  removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* curr= head;

        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        if(n==count){
          ListNode* newHead=head->next;
          delete head;
          return newHead;
        }
        int target = count-n;
         curr=head;
         int k=1;
         while(k<target && curr->next!=NULL){
            curr=curr->next;
            k++;
         }
         ListNode* todelete = curr->next;
         curr->next=curr->next->next;
         delete todelete;
        
        return head;
    }
};