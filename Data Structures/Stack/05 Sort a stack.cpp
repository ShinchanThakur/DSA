//SORT A STACK

//USING RECURSION

void sortedInsert(stack<int> &s, int a){
    if(s.empty() or s.top() < a){
        s.push(a);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, a);
    s.push(temp);
}

void sortStack(stack<int> &s){
    if(s.empty())
        return;
    int a = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, a);
}

//Time complexity: O(n^2)
//Space complexity: O(1)

/*************************************************************************************************/

//USING TEMP STACK

void sortStack(stack<int> &s){
    stack<int> tempStack;
    while(s.size()){
        int temp = s.top();
        s.pop();
        while(tempStack.size() and tempStack.top() > temp){
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    s = tempStack;
}

//Time complexity: O(n^2)
//Space complexity: O(n)

//Problem link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1