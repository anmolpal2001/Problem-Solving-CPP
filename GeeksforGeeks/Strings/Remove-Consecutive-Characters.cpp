Ques : https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

Solution : 
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string result="";
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!=S[i-1])
            {
                result.push_back(S[i]);
            }
        }
        return result;
    }
};
