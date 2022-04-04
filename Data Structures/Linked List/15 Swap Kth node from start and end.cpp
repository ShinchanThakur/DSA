//SWAP Kth NODE FROM START AND END

//Swap values

ListNode* swapNodes(ListNode* head, int k) {
    ListNode *kthFromStart = head, *kthFromEnd = head, *temp;
    for(int i=1; i<k; i++)
        kthFromStart = kthFromStart->next;
    temp = kthFromStart->next;
    while(temp)
        kthFromEnd = kthFromEnd->next, temp = temp->next;
    swap(kthFromStart->val, kthFromEnd->val);
    return head;
}

/********************************************************************************************************/

//Swap nodes

ListNode* swapNodes(ListNode* head, int k) {
    ListNode **kthFromStart = &head, **kthFromEnd = &head, *temp;
    for(int i=1; i<k; i++)
        kthFromStart = &(*kthFromStart)->next;
    temp = (*kthFromStart)->next;
    while(temp)
        kthFromEnd = &(*kthFromEnd)->next, temp = temp->next;
    swap(*kthFromStart, *kthFromEnd);
    swap((*kthFromStart)->next, (*kthFromEnd)->next);
    return head;
}

/*******************************************************************************************************/

//Swap manually
//Learn this from here https://www.geeksforgeeks.org/swap-kth-node-from-beginning-with-kth-node-from-end-in-a-linked-list/

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
//              https://practice.geeksforgeeks.org/problems/swap-kth-elements5500/1/