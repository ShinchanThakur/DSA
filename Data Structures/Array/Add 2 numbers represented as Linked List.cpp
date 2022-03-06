//ADD TWO NUMBERS REPRESENTED AS A LINKED LIST IN REVERSE ORDER

ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
    ListNode *dummyHeadForSumList = new ListNode();
    ListNode * sumList = dummyHeadForSumList;
    int carry = 0, sum;
    while(list1 or list2 or carry){
        sum = carry;
        if(list1){
            sum += list1 -> val;
            list1 = list1 -> next;
        }
        if(list2){
            sum += list2 -> val;
            list2 = list2 -> next;
        }
        carry = sum / 10;
        sum = sum % 10;
        sumList -> next = new ListNode(sum);
        sumList = sumList -> next;
    }
    sumList = dummyHeadForSumList -> next
    return sumList;
}

//Time complexity - O(n)
//Space complexity - O(n)

//Problem Link - https://leetcode.com/problems/add-two-numbers/