Ques : https://leetcode.com/problems/reverse-words-in-a-string/

Solution : 
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            } else {
                str.push_back(s[i]);
            }
        }
        
        if (!str.empty()) {
            st.push(str);
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += ' ';
            }
        }
        
        return ans;
    }
};
