class Solution {
public:

   
    ListNode* reverseLL(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != NULL && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* kth = getKthNode(prevGroupEnd->next, k);
            if (kth == NULL) break;

            ListNode* nextGroupStart = kth->next;

         
            kth->next = NULL;

  
            ListNode* newHead = reverseLL(prevGroupEnd->next, k);

       
            ListNode* oldHead = prevGroupEnd->next;
            prevGroupEnd->next = newHead;
            oldHead->next = nextGroupStart;

            prevGroupEnd = oldHead;
        }

        return dummy->next;
    }
};