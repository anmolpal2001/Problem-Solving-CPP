Ques : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

Solution : 
class Solution{
public:	
	int isPalindrome(string S)
	{
	    int s=0;
	    int e=S.length()-1;
	    int flag=0;
	    while(s<=e)
	    {
	       if(S[s]!=S[e])
	       {
	           return 0;
	       }
	       s++;
	       e--;
	    }
    	return 1;
	}
};
