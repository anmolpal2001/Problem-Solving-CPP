Ques : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

Solution : 
char* reverse(char *S, int len)
{
    stack<char> s;
    for(int i=0;i<len;i++)
    {
        s.push(S[i]);
    }
    for(int i=0;i<len;i++)
    {
        S[i]=s.top();
        s.pop();
    }
    return S;
}
