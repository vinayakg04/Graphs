class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=0;
        long long head=0;
        long long unique=0;
        long long sum=0;
        unordered_map<int,int> mp;
        for(int tail=0;tail<n;tail++){
            sum+=nums[tail];
            mp[nums[tail]]++;

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

            if(unique==k){
                res=max(res,sum);
            }
        }

        return res;
    }
};
