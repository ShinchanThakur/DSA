//CYCLE IN A LINKED LIST

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

/******************************************************************************************************/

// FIND STARTING POINT OF A LOOP IN A LINKED LIST

ListNode *detectCycle(ListNode *head) {
    ListNode *slow, *fast, *entry;
    slow = fast = entry = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(entry != slow){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/linked-list-cycle-ii/