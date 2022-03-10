//ROTATE LINKED LIST K TIMES

ListNode* rotateRight(ListNode* head, int k) {
    if(!head or !(head->next) or !k)    return head;

    ListNode *tail = head;
    int len = 1;
    //finding length of ll
    while(tail->next)   len++, tail = tail->next;
    //connecting tail to head, making LL circular
    tail->next = head;

    k = k%len;
    int end = len - k;
    ListNode *newTail = tail, *newHead;
    if(k)
        while(end--)    newTail = newTail->next;
    newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/rotate-list/