class Solution {
public:
    void solve(int num,int n,vector<int>& result){
        if(num>n){
            return;
        }

        result.push_back(num);

        //explore all possibilities of num by appending numbers

        for(int append=0;append<=9;append++){
            int newNum=num*10 + append;
            if(newNum > n){
                return;
            }else{
                solve(newNum,n,result);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int result=0;
        for(int num=1;num<=9;num++){
            solve(num,n,res);
        }

        return res;
    }
};
