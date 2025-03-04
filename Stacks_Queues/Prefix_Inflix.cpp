class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> is;
        for(int i=pre_exp.length();i>=0;i--){
            char ch=pre_exp[i];
            
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                string is2=is.top();
                is.pop();
                string is1=is.top();
                is.pop();
                string ival= "(" + is2 + string(1,ch) + is1 + ")";
                is.push(ival);
                
            }else{
                is.push(string(1,ch));
            }
        }
        
        string ans= is.top();
        return ans;
    }
};
