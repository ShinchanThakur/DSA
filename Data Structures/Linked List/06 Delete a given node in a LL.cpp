//DELETE GIVEN NODE IN A LINKED LIST (NOT A TAIL NODE)

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

//Time Complexity: O(1)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/