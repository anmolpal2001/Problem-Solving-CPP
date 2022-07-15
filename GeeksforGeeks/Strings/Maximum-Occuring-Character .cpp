// Question : https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        int number = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                number = str[i] - 'a';
            }
            arr[number]++;
        }
        int maxi = -1, ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (maxi < arr[i])
            {
                ans = i;
                maxi = arr[i];
            }
        }
        char finalAns = 'a' + ans;
        return finalAns;
    }
};
int main()
{
    string str;
    cin >> str;
    Solution obj;
    cout << obj.getMaxOccuringChar(str) << endl;
}
