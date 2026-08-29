#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Handle collisions only when current asteroid moves left (<0)
            // and stack top asteroid moves right (>0)
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (st.top() < -a) {
                    // Top asteroid is smaller, it explodes
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    // Both are equal, both explode
                    st.pop();
                }
                // Current asteroid is destroyed
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
