
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return 0;

        int count=0;
        // set<int> s;
        // for(auto i: nums){
        //     s.insert(i);
        // }

        // auto e=s.end();
        // int max_ele=*e;

        // while()

        // auto it=s.begin();
        // int min_ele=*it;
        // it++;
        // int sec_min_ele=*it;

        // s.erase(min_ele);
        // s.erase(sec_min_ele);
        
        // int new_ele= min(min_ele,sec_min_ele) *2 + max(min_ele,sec_min_ele);

        // s.insert(new_ele);

        typedef long long ll;
        priority_queue<ll,vector<ll>,greater<ll>> minh;
        for(auto i: nums){
            minh.push(i);
        }

        while(minh.size()>0 && minh.top()<k){
            ll min_ele=minh.top();
            minh.pop();
            ll sec_min_ele=minh.top();
            minh.pop();

            long long new_ele=(min_ele* 2) + sec_min_ele;

            minh.push(new_ele);
            count++;
        }

        return count;

        

    }
};
