class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                int top = st.top();
                int sum = top + asteroid;

                if (sum < 0) {  // Current asteroid wins
                    st.pop();
                } else if (sum > 0) {  // Stack asteroid wins
                    destroyed = true;
                    break;
                } else {  // Both asteroids explode
                    st.pop();
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

