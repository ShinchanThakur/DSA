//CHECK IF A LINKED LIST IS A PALINDROME

//LIST ALTERATION IS ALLOWED

ListNode *getMiddleNode(ListNode *head){
    ListNode *slow = head, *fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *reverse(ListNode *head){
    if(!head or !(head->next))
        return head;
    ListNode *nex = head->next;
    ListNode *newHead = reverse(nex);
    nex->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode* head) {
    //finding middle node
    if(!head or !(head->next))
        return true;
    ListNode *middleNode = getMiddleNode(head);
    middleNode->next = reverse(middleNode->next);
    ListNode *firstPart = head, *secondPart = middleNode->next;
    while(secondPart){
        if(firstPart->val != secondPart->val)   return false;
        firstPart = firstPart->next;    secondPart = secondPart->next;
    }
    return true;
}

/******************************************************************************************************************/

//LIST ALTERATION IS NOT ALLOWED

bool pal(ListNode **a, ListNode *b){
    if(!b)    return true;
    if(!pal(a, b->next))    return false;
    if((*a)->val != b->val)    return false;
    *a = (*a)->next;
    return true;
}
bool isPalindrome(ListNode* head) {
    if(!head or !(head->next))
        return true;
    return pal(&head, head);
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/palindrome-linked-list/