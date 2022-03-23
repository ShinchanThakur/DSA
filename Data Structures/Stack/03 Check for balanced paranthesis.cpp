//CHECK FOR BALANCED PARANTHESIS

bool isValid(string expression) {
    stack<char> s;
    for(char c: expression){
        if(c == '{' or c == '(' or c == '[')
            s.push(c);
        else{
            if(s.empty())
                return false;
            char top = s.top();
            s.pop();
            if((top == '{' and c == '}') or (top == '(' and c == ')') or (top == '[' and c == ']'))
                continue;
            else
                return false;
        }
    }
    return s.empty();
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/valid-parentheses/