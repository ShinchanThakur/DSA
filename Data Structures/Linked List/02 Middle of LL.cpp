// FIND MIDDLE OF A LINKED LIST

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int countNodes(ListNode *head)
    {
        int nodeCount = 0;
        while (head)
        {
            nodeCount++;
            head = head->next;
        }
        return nodeCount;
    }
    ListNode *getMiddleNodeByCounting(ListNode *head)
    {
        int nodeCount = countNodes(head);
        ListNode *middleNode = head;
        for (int i = 0; i < nodeCount / 2; i++)
        {
            middleNode = middleNode->next;
        }
        return middleNode;
    }
    ListNode *getMiddleNodeUsingHareAndTortoiseMethod(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *middleNode;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        middleNode = slow;
        return middleNode;
    }
    ListNode *middleNode(ListNode *head)
    {
        return getMiddleNodeUsingHareAndTortoiseMethod(head);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/