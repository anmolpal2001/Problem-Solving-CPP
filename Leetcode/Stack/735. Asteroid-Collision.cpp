Ques : https://leetcode.com/problems/asteroid-collision/

Solution : 
// TC : O(N)  and SC : O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
        for (int asteroid : asteroids) 
        {
            bool exploded = false;
            while(!st.empty() && asteroid<0 && st.top()>0) 
            {
                int prevAsteroid = st.top();
                st.pop();
                if (abs(prevAsteroid) == abs(asteroid)) {
                    exploded = true;
                    break;
                } 
                else if(abs(prevAsteroid) > abs(asteroid)) 
                {
                    asteroid = prevAsteroid;
                }
            }
            if (!exploded) {
                st.push(asteroid);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) 
        {
            result[i] = st.top();
            st.pop();
        }
        return result; 
    }
};
