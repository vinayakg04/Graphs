class Solution {
public:
    int MOD = 1e9 + 7; // Correct MOD value

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL(n, -1); // Next Smaller Left indices
        vector<int> NSR(n, n);  // Next Smaller Right indices
        stack<int> st;

        // Compute NSL (Next Smaller Left)
         for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            NSL[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
   
        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Compute NSR (Next Smaller Right)
        for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            NSR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

        // Compute sum of subarray minimums
        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];  // Distance to previous smaller element
            long long right = NSR[i] - i; // Distance to next smaller element
            minSum = (minSum + (arr[i] * left % MOD * right % MOD) % MOD) % MOD;
        }

        return (int) minSum;
    }
};
