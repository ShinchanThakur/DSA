//REVERSE LINKED LIST IN GROUPS OF SIZE K

int getLength(ListNode *head){
    int len = 0;
    while(head) len++, head = head->next;
    return len;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    int len = getLength(head);
    ListNode *dummyHead = new ListNode();
    ListNode *prev = dummyHead, *curr = head, *nex, *currHead, *currTail;
    while(len >= k){
        currHead = prev;
        currTail = curr;
        for(int i=0; i<k; i++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        currHead->next = prev;
        currTail->next = curr;
        prev = currTail;
        len -= k;
    }
    return dummyHead->next;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/