class Solution {
public:
    vector<int> NSL(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
        }
        return res;
    }

    vector<int> NSR(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n);
        stack<int> st;

        
        for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
       }
       return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL_index = NSL(heights);
        vector<int> NSR_index = NSR(heights);

        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int width = NSR_index[i] - NSL_index[i] - 1;
            int area = heights[i] * width;
            maxA = max(maxA, area);
        }

        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> v(n, 0);
        int mx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    v[j] = 0;
                } else {
                    v[j] += 1; // Accumulate height
                }
            }
            mx = max(mx, largestRectangleArea(v));
        }

        return mx;
    }
};
