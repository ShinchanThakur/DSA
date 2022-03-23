//IMPLEMENT STACKS USING ARRAYS

class Stack {
private:
    int topp, capacity, *arr;
public:
    
    Stack(int capacity) {
        topp = -1;
        this->capacity = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        if(topp < capacity-1)
            arr[++topp] = num;
    }

    int pop() {
        if(topp > -1)
            return arr[topp--];
        else
            return -1;
    }
    
    int top() {
        if(topp > -1)
            return arr[topp];
        else
            return -1;
    }
    
    int isEmpty() {
        return topp == -1;
    }
    
    int isFull() {
        return topp == capacity - 1;
    }
    
};

//Time complexity: O(1)
//Space complexity: O(n)

//Problem link: https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?topList=striver-sde-sheet-problems