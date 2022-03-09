//REMOVE Nth NODE FROM END

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode();
    ListNode *fast = dummy, *slow = dummy;
    dummy->next = head;

    for(int i=0; i<n and fast; i++)
        fast = fast->next;
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/