class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* ans = nullptr;

        while (curr != nullptr) {
            ListNode* newHead = curr->next;

            curr->next = ans;
            ans = curr;
            curr = newHead;
        }

        return ans;
    }
};