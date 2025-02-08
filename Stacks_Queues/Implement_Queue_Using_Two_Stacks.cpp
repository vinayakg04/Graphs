class MyQueue {
public:
    stack<int> ip;
    stack<int> op;
    int peekEle=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
      if(ip.empty()){
        peekEle=x;
      }

      ip.push(x);
    }
    
    int pop() {
       if(op.empty()){
        //Put element in the output O(N)
        while(!ip.empty()){
            op.push(ip.top());
            ip.pop();
        }
       }

       int val=op.top();
       op.pop();
       return val;
    }
    
    int peek() {
        if(!op.empty()) return op.top();

        return peekEle;
    }
    
    bool empty() {
        if(ip.size()==0 && op.size()==0){
            return true;
        }

        return false;
    }
};
