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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* res = new ListNode();
        ListNode* out = res;

        while(list1 && list2)
        {
            if(list1->val <= list2->val){
                res->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                res->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            res = res->next;
        }

        res->next = list1 ? list1 : list2;

        // while(list1){
        //     res->next = new ListNode(list1->val);
        //     list1 = list1->next;
        // }
        // while(list2){
        //     res->next = new ListNode(list2->val);
        //     list2 = list2->next;
        // }

        return out->next;

    }
};