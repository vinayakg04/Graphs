class Solution {
public:
    vector<int> NSL(vector<int>& nums){
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        return res;
    }

    vector<int> NSR(vector<int>& nums){
        int n=nums.size();
        vector<int> res(n,n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
            res[st.top()]=i;
            st.pop();
            }
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL_index=NSL(heights);
        vector<int> NSR_index=NSR(heights);
        
        int n=heights.size();
        vector<int> area(n,0);

        for(int i=0;i<n;i++){
            int width=NSR_index[i]-NSL_index[i]-1;
            int a=heights[i]*width;
            area.push_back(a);
        }

        int m=area.size();
        int maxA=0;
        for(int i=0;i<m;i++){
            maxA=max(maxA,area[i]);
        }

        return maxA;
    }
};
