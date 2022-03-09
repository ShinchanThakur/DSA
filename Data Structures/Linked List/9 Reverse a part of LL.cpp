//REVERSE A PART OF LINKED LIST

//ITERATIVE

ListNode* reverseBetween(ListNode* head, int left, int right) {
    int count = 1;
    ListNode *curr = head, *prev = NULL, *nex;
    while(curr and count<left){
        prev = curr;
        curr = curr->next;
        count++;
    }
    ListNode *end = curr, *start = prev;
    while(curr and count<=right){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        count++;
    }
    end->next = curr;
    if(start == NULL)
        head = prev;
    else
        start->next = prev;
    return head;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/reverse-linked-list-ii/

//Learn its recursive from solution section