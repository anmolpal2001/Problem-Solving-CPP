Ques : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

Solution 1 : 
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(auto ch:s)
        {
            if(result.size()==0)
            {
                result.push_back(ch);
            }
            else if(result.back()==ch)
            {
                result.pop_back();
            }
            else
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};

// Using Stack
Solution 2 : 
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        stack<char> charStack;
        for(auto ch:s)
        {
            if(!charStack.empty()&& charStack.top()==ch)
            {
                charStack.pop();
            }
            else
            {
                charStack.push(ch);
            }
        }
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
    }
};
