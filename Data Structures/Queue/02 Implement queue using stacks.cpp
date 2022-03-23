//IMPLEMENT QUEUE USING STACK

//PUSH COMPLEXITY : O(n)

class MyQueue {
private:
    stack<int> input, output;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(input.size()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(output.size()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if(this->empty())
            return -1;
        int prevFront = input.top();
        input.pop();
        return prevFront;
    }
    
    int peek() {
        if(this->empty())
            return -1;
        return input.top();
    }
    
    bool empty() {
        return input.size() == 0;
    }
};

//Time complexity: O(n) for push
//                 O(1) for others
//Space complexity: O(n)

/******************************************************************************************************/

//PUSH COMPLEXITY : Amortised O(1)

class MyQueue {
private:
    stack<int> input, output;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(this->empty())
            return -1;
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int prevFront = output.top();
        output.pop();
        return prevFront;
    }
    
    int peek() {
        if(this->empty())
            return -1;
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.size() + output.size() == 0;
    }
};

//Time complexity: O(1) for push
//                 O(n) for others (sometimes O(1) too)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/implement-queue-using-stacks/