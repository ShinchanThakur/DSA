//FLATTEN A LINKED LIST WITH NEXT AND BOTTOM POINTERS

Node *mergeLists(Node *list1, Node *list2){
    Node *dummyHead = new Node(0), *temp;
    temp = dummyHead;
    while(list1 and list2){
        if(list1->data <= list2->data){
            temp->bottom = list1;
            temp = temp->bottom;
            list1 = list1->bottom;
        }
        else{
            temp->bottom = list2;
            temp = temp->bottom;
            list2 = list2->bottom;
        }
    }
    if(list1)   temp->bottom = list1;
    else        temp->bottom = list2;
    return dummyHead->bottom;
}

Node *flatten(Node *root)
{
   if(!root or !(root->next))   return root;
   root->next = flatten(root->next);
   return mergeLists(root, root->next);
}

//Time complexity: O(n*n*m)
//Space complexity: O(n*m)  -> Recursion stack

//Problem Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

//Read this link for understanding time and space complexity: https://www.geeksforgeeks.org/flattening-a-linked-list/