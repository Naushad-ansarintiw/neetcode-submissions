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
private:
    ListNode* newHead = nullptr;
public:
    ListNode* reverseLinkedList(ListNode* node) {
        if(node == nullptr) return nullptr;
        ListNode* next = reverseLinkedList(node->next);
        if(next != nullptr) {
            next->next = node; 
            node->next = nullptr;
        } else {
            newHead = node;
            node->next = nullptr;
        }
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = reverseLinkedList(head);
        return newHead;
    }
};
