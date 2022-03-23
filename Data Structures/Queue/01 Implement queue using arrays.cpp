//IMPLEMENT QUEUE USING ARRAYS

class Queue {
private:
    int *arr, start, end, capacity, currSize;
public:
    Queue() {
        capacity = 5000;
        arr = new int[capacity];
        start = -1;
        end = -1;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    void enqueue(int data) {
        if(currSize == capacity)
            return;
        if(start == -1)
            start++;
        end = (end + 1)%capacity;
        arr[end] = data;
        currSize++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        int prevFront = front();
        start = (start + 1)%capacity;
        currSize--;
        return prevFront;
    }

    int front() {
        if(isEmpty())
            return -1;
        return arr[start];
    }
};

//Time complexity: 
//Space complexity: 

//Problem link: https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems