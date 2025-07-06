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
    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy;
        ListNode* node = &dummy;

        while(l1 && l2){
            if(l1->val > l2->val){
                node->next = l2;
                l2 = l2->next;
            }
            else{
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        node->next = l1 ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(auto& list: lists)
        // {
        //     while(list){
        //         pq.push(list->val);
        //         list = list->next;
        //     }
        // }
        // ListNode* head = new ListNode();
        // ListNode* res = head;
        // while(!pq.empty()){
        //     head->next = new ListNode(pq.top());
        //     pq.pop();
        //     head = head->next;
        // }
        // return res->next;

        // --------------------------------------------------------

        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> tmp;
            for(size_t i = 0; i < lists.size() ; i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                tmp.push_back(mergeLists(l1,l2));
            }
            lists = tmp;
        }
        return lists[0];
    }
};