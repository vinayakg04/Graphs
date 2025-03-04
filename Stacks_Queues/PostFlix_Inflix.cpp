class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> is;
        for(int i=0;i<exp.length();i++){
            char ch=exp[i];
            
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                string is2=is.top();
                is.pop();
                string is1=is.top();
                is.pop();
                string ival= "("+ is1 + string(1,ch) + is2 + ")";
                is.push(ival);
            
                
            }else{
                is.push(string(1,ch));
            }
        }
        
        return is.top();
    }
};
