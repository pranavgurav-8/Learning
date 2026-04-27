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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode *temp = head;
        ListNode *before = temp;
        int pos = 1;

        while(temp != NULL){
            if(pos < left){
            before = temp;
            temp = temp->next;
            pos++;
            break;
        }
        }
        ListNode *curr = temp;
        ListNode *prev = NULL;

        int times = right - left + 1;
        while(times--){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        temp->next = curr;
        if(before){
            before->next = prev;
        }
        else{
            return prev;
        }

        
        

        return head;


        
    }
};