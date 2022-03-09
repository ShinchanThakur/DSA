//DETECT CYCLE IN A LINKED LIST

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)    return true;
    }
    return false;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/linked-list-cycle/