//IMPLEMENT STACK USING QUEUE

class MyStack {
private:
    queue<int> *q;
public:
    MyStack() {
        q = new queue<int>();
    }
    
    void push(int x) {
        int prevSize = q->size();
        q->push(x);
        while(prevSize--){
            q->push(q->front());
            q->pop();
        }
    }
    
    int pop() {
        if(q->size()){
            int prevTop = q->front();
            q->pop();
            return prevTop;
        }
        else
            return -1;
    }
    
    int top() {
        if(q->size())
            return q->front();
        else
            return -1;
    }
    
    bool empty() {
        return q->size() == 0;
    }
};

//Time complexity: O(n) for push
//                 O(1) for others
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/implement-stack-using-queues/