class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* prev = NULL ;
        ListNode* newhead = head ;
        int count = 0 ;
        int variable = k ;
        int r = 0 ;

        if ( head == NULL ){
            return head;
        }

        else {
            while (k > 0) {
            prev = curr;
            curr = curr->next;
            count += 1;
            

            if ( curr == NULL){
                return head;
            }

            if (curr->next == NULL) {

                if (  (k = (variable % (count + 1 )) -  r ) >0 ){
                    k = (variable % (count + 1 )) -  r ; // here i want to calculate the remainder  and then subtract  r 
                count = 0;
                curr->next = newhead;
                newhead = curr ;
                prev->next = NULL;
                k -= 1; 
                r += 1;  
                }

                else {
                    return head ;
                }
                        
            }

            
        }
        }

        return newhead;
    }
};