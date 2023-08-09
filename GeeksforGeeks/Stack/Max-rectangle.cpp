Ques : https://practice.geeksforgeeks.org/problems/max-rectangle/1

Solution : 
// TC : O(NxM) and SC : O(M)
class Solution{
  public:
  
  int largestRectangleArea(int *arr,int m) {
        int maxAns=0;
        stack<int> st;
        for(int i=0;i<=m;i++)
        {
            while(!st.empty() && (i==m || arr[st.top()]>=arr[i]))
            {
                int height=arr[st.top()];
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
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                {
                    M[i][j]=M[i][j]+M[i-1][j];
                }
                else
                {
                    M[i][j]=0;
                }
            }
            area = max(area, largestRectangleArea(M[i],m));
        }
        return area;
    }
};
