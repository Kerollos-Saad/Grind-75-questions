class MyQueue {

private:
    stack<int> stA;
    stack<int> stB;

public:
    MyQueue() {}
    
    void push(int x) {
        stA.push(x);
    }
    
    int pop() {
        while(!stA.empty()){
            stB.push(stA.top());
            stA.pop();
        }
        int res = stB.top();
        stB.pop();
        while(!stB.empty()){
            stA.push(stB.top());
            stB.pop();
        }
        return res;
    }
    
    int peek() {
            while(!stA.empty()){
            stB.push(stA.top());
            stA.pop();
        }
        int res = stB.top();
        while(!stB.empty()){
            stA.push(stB.top());
            stB.pop();
        }
        return res;
    }
    
    bool empty() {
        return stA.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */