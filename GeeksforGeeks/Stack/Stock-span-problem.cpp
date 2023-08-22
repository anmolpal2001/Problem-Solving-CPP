Ques : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

Solution : 
// TC : O(N) and SC : O(N)
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans;
        stack<int>s;
        s.push(0);
        ans.push_back(1);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && price[s.top()]<=price[i])
            {
                s.pop();
            }
            int span=s.empty()?i+1:i-s.top();
            ans.push_back(span);
            s.push(i);
        }
        return ans;
    }
};
