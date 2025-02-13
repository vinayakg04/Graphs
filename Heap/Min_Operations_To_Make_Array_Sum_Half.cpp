class Solution {
public:

    int halveArray(vector<int>& nums) {
        int n=nums.size();
        double totalSum=0;
        for(auto i: nums){
            totalSum+=i;
        }

        double k=totalSum/2.0;

        long long count=0;
        priority_queue<double> maxh;
        for(auto i: nums){
            maxh.push(i);
        }

        int least_sum=0;
        while(maxh.size()>0 && totalSum>k){
            double max_ele=maxh.top();
            maxh.pop();

            double new_ele=max_ele/2;

            totalSum=totalSum-(max_ele-new_ele);
            maxh.push(new_ele);
            count++;
    
        }

        return (int)count;
    }
};
