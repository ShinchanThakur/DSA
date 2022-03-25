//IMPLEMENT MINSTACK

// BRUTE FORCE

class MinStack {
private:
    stack<pair<int, int>> s;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size())
            s.push({val, min(val, s.top().second)});
        else
            s.push({val, val});
    }
    
    void pop() {
        if(s.size())
            s.pop();
    }
    
    int top() {
        if(s.size())
            return s.top().first;
        else
            return -1;
    }
    
    int getMin() {
        if(s.size())
            return s.top().second;
        else
            return -1;
    }
};

//Time complexity: O(1)
//Space complexity: O(2*n)

/******************************************************************************************************/

// OPTIMISED

class MinStack {
private:
    stack<long long int> s;
    long long int mini;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size()){
            if(val < mini){
                mini = 2ll * val - mini;
                s.push(mini);
                mini = val;
            }
            else
                s.push(val);
        }
        else{
            mini = val;
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        if(s.top() < mini)
            mini = 2 * mini - s.top();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        if(s.top() < mini)
            return mini;
        else
            return s.top();
    }
    
    int getMin() {
        if(s.size())
            return mini;
        else
            return -1;
    }
};

//Time complexity: O(1)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/min-stack/