vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);   // Initialize result array with -1
    stack<int> st;            // Monotonic decreasing stack (stores indices)

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while current element is greater
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i]; // Update result for that index
            st.pop();
        }
        st.push(i); // Push the current index onto the stack
    }
    return res;
}
