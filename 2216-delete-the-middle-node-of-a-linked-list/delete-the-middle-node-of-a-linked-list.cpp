class Solution {
public:
ListNode* deleteMiddle(ListNode* head) {

if (head == nullptr || head->next == nullptr) {
return nullptr;
}

ListNode* front = head;
ListNode* back = head;
ListNode* prev = nullptr;

while (front != nullptr && front->next != nullptr){
front = front->next->next;
prev = back;
back = back->next;
}

prev->next = back->next;

return head;
}
};