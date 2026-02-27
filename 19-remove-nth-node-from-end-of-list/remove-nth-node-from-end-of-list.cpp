class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {

ListNode* kundan = head;
ListNode* himanshu = head;

while (n > 0) {
kundan = kundan->next;
n--;
}

if (kundan == nullptr) {
return head->next;
}

while (kundan->next != nullptr) {
kundan = kundan->next;
himanshu = himanshu->next;
}

himanshu->next = himanshu->next->next;

return head;
}
};