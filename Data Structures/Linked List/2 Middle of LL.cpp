//FIND MIDDLE OF A LINKED LIST

ListNode* middleNodeOfLL(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/