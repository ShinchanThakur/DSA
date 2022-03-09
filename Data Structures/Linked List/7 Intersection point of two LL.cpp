//FIND INTERSECTION POINT OF TWO LINKED LISTS

//Brute force

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA or !headB)
        return NULL;
    while(headA){
        ListNode *tempB = headB;
        while(headB){
            if(headA == headB) return headA;
            headB = headB->next;
        }
        headB = tempB;
        headA = headA->next;
    }
    return NULL;
}

//Time complexity: O(n^2)
//Space complexity: O(1)

/*************************************************************************************************************/

//Hashing

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> ANodeSet;
    while(headA){
        ANodeSet.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(ANodeSet.find(headB) != ANodeSet.end())  return headB;
        headB = headB->next;
    }
    return NULL;
}

//Time complexity: O(n)
//Space complexity: O(n)

/*************************************************************************************************************/

//Difference Method

int getDifference(ListNode *headA, ListNode *headB){
    int len1 = 0, len2 = 0;
    while(headA)    len1++, headA = headA->next;
    while(headB)    len2++, headB = headB->next;
    return len1 - len2;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int diff = getDifference(headA, headB);
    if(diff < 0)    while(diff++ != 0)  headB = headB->next;
    else    while(diff-- != 0)  headA = headA->next;
    while(headA){
        if(headA == headB)  return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

//Time complexity: O(n)
//Space complexity: O(1)

/*************************************************************************************************************/

//Easy to code (Difference Method)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tempA = headA, *tempB = headB;
    while(tempA != tempB){
    	//If there is no intersection, it will stop after maximum 2 loops
        tempA = tempA == NULL ? headB : tempA->next;
        tempB = tempB == NULL ? headA : tempB->next;
    }
    return tempA;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/