// REVERSE A LINKED LIST

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
    ListNode *reverseListIterative(ListNode *head)
    {
        ListNode *current_p = head, *prev_p = NULL, *next_p;
        while (current_p)
        {
            next_p = current_p->next;
            current_p->next = prev_p;
            prev_p = current_p;
            current_p = next_p;
        }
        head = prev_p;
        return head;
    }

    ListNode *reverseListRecursive(ListNode *current_p)
    {
        if (current_p == NULL || current_p->next == NULL)
            return current_p;
        ListNode *new_head = reverseListRecursive(current_p->next);
        ListNode *new_tail = current_p->next;
        new_tail->next = current_p;
        current_p->next = NULL;
        return new_head;
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverseListIterative(head);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Problem Link: https://leetcode.com/problems/reverse-linked-list/