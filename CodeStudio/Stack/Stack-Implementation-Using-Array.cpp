Ques : https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209

Solution : 
// Stack class.
class Stack {
    int *arr;
    int topIndex;
    int capacity;
public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        topIndex=-1;
        this->capacity=capacity;
    }

    void push(int num) {
        if(topIndex!=capacity-1)
        {
            topIndex++;
            arr[topIndex]=num;
        }
    }

    int pop() {
        if(topIndex==-1)
        {
            return -1;
        }
        int res=arr[topIndex];
        topIndex--;
        return res;
    }
    
    int top() {
        if(topIndex!=-1)
        {
            return arr[topIndex];
        }
        return -1;
    }
    
    int isEmpty() {
        if(topIndex==-1)
        {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(topIndex==capacity-1)
        {
            return 1;
        }
        return 0;
    }
    
};
