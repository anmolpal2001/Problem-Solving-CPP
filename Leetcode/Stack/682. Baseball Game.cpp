Ques : https://leetcode.com/problems/baseball-game/

Solution : 
// TC : O(N) and SC : O(N)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int score;
        for(string &op:operations)
        {
            if(op=="C")
            {
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(op=="D")
            {
                if(!st.empty()){
                    int top=st.top();
                    st.push(2*top);
                }
            }
            else if(op=="+")
                {
                    if(st.size()>=2)
                    {
                        int ele1=st.top();
                        st.pop();
                        int ele2=st.top();
                        st.push(ele1);
                        int sum=ele1+ele2;
                        st.push(sum);
                    }
                }
            else
            {
                score=stoi(op);
                st.push(score);
            }
        }
        int result=0;
        while(!st.empty())
        {
            int top=st.top();
            result+=top;
            st.pop();
        }
        return result;
    }
};
