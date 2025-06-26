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

    ListNode* recursively(ListNode* prev, ListNode* node)
    {
        if(node == nullptr)
            return prev;
        
        ListNode* newHead = recursively(node, node->next);
        node->next = prev;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        return recursively(nullptr, head);
    }
};