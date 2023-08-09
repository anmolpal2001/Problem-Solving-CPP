Ques : https://leetcode.com/problems/largest-rectangle-in-histogram/

Solution 1 : 
// TC : O(N) + O(N) + O(N) and SC : O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int leftSmall[n],rightSmall[n];
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                leftSmall[i]=0;
            else
                leftSmall[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                rightSmall[i]=n-1;
            else
                rightSmall[i]=st.top()-1;
            st.push(i);
        }
        int maxAns=0;
        for(int i=0;i<n;i++)
        {
            maxAns=max(maxAns,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxAns;
    }
};

Solution 2 : 
// TC : O(N) + O(N) and SC : O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxAns=0;
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())  
                    width=i;
                else 
                    width = i-st.top()-1;
                maxAns = max(maxAns, width*height);
            }
            st.push(i);
        }
        return maxAns;
    }
};
