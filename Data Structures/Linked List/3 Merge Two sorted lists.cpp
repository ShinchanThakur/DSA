//MERGE TWO SORTED LINKED LISTS

ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val > list2->val) swap(list1, list2);
    //We always want to keep smaller value in list1
    ListNode *lastSortedNode, *newHead = list1;
    while(list1 and list2){
        while(list1 and list1->val <= list2->val){
            lastSortedNode = list1;
            list1 = list1->next;
        }
        lastSortedNode->next = list2;
        swap(list1, list2);
    }
    return newHead;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/