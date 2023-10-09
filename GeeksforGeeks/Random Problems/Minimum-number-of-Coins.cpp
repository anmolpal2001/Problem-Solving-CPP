Ques : https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

Solution : 
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>result;
        vector<int> currency = {2000,500,200,100,50,20,10,5,2,1};
        for(int i=0;i<currency.size();i++)
        {
            while(N>=currency[i])
            {
                N-=currency[i];
                result.push_back(currency[i]);
            }
        }
        
        return result;
    }
};
