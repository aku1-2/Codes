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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow= head;
        ListNode* fast = head->next;
        ListNode* distinct_point = nullptr;
        while(fast){
           if(slow->val==fast->val){
               int value= fast->val;
               while(fast && fast->val==value){
                fast= fast->next;
               }
               if(distinct_point==nullptr){
                head = fast;
               }
               else{
                distinct_point->next = fast;
               }
               slow=fast;
               if(fast){
                fast= fast->next;
               }
            }
              else{ 
            distinct_point=slow;
            slow=fast;
            fast= fast->next;
            }
        }
        return head;
    }
};