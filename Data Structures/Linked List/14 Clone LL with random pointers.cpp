//CLONE LINKED LIST WITH RANDOM POINTERS

Node* copyRandomList(Node* head) {
    if(!head)   return head;
    Node *node = head, *nex, *copyNode;
    //inserting copyNode between original nodes
    while(node){
        nex = node->next;
        copyNode = new Node(node->val);
        node->next = copyNode;
        copyNode->next = nex;
        node = nex;
    }
    node = head, copyNode = head->next;
    //setting random nodes for copyNodes
    while(copyNode){
        copyNode->random = node->random ? node->random->next : NULL;
        node = copyNode->next;
        copyNode = node ? node->next : NULL;
    }
    Node *original = head, *copy = head->next;
    Node *copyListHead = copy;
    //separating copy and original list
    while(copy){
        original->next = copy->next;
        original = original->next;
        copy->next = original ? original->next : NULL;
        copy = copy->next;
    }
    return copyListHead;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/