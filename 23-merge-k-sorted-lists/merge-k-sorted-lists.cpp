class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto node : lists) {
            if (node != NULL)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};