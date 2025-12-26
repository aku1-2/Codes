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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==nullptr || head->next==nullptr ||k==0) 
       return head;
       ListNode* curr= head;
       int len=1;
       while(curr->next){
        len++;
        curr=curr->next;
       } 
       curr->next=head;// Circular list
       k=k%len; //handling k>len cases
       int newlen = len-k;

       ListNode* newtail= curr;
       while(newlen--){
        newtail= newtail->next;
       }
       ListNode* newHead = newtail->next;
         newtail->next= nullptr;
         return newHead;

    }
};