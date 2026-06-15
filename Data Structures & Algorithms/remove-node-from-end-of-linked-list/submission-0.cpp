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
    int calculatelen(ListNode* node){
        int cnt = 0; 
        while(node != NULL) {
            cnt += 1; 
            node = node->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = calculatelen(head);
        if(len == 0) return head;
        int mv = len - n;
        if(mv == 0) return head->next; 
        int cnt = 1; 
        ListNode* temp = head;
        while(cnt<mv) {
            temp = temp->next;
            cnt +=1; 
        }
        ListNode* removeNext = temp->next->next; 
        temp->next = removeNext; 
        return head; 
    }
};
