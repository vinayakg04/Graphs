class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
      //USING TWO QUEUES
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }

        // swap(q1,q2);
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();        }
    }
    
    int pop() {
        int result=q1.front();
        q1.pop();
        
        return result;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
