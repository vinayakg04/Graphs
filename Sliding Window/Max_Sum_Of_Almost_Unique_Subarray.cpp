class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long res=0;
        long long head=0;
        long long unique=0;
        long long sum=0;

        unordered_map<int,int> mp;
        for(int tail=0;tail<n;tail++){
            mp[nums[tail]]++;
            sum+=nums[tail];

            if(mp[nums[tail]]==1){
                unique++;
            }

            if(tail-head+1>k){
                sum-=nums[head];
                mp[nums[head]]--;
                if(mp[nums[head]]==0){
                    unique--;
                }
                head++;
            }

            if(unique>=m){
                res=max(res,sum);
            }
        }

        return res;
        
    }
};
