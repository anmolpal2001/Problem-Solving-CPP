Ques : https://leetcode.com/problems/evaluate-reverse-polish-notation/

Solution :
// TC : O(N) and SC : O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x1,x2,r;
        for(int i=0;i<tokens.size();i++)
        {
            string ch=tokens[i];
            if(ch=="+")
            {
                x2=st.top();
                st.pop();
                x1=st.top();
                st.pop();
                r=x1+x2;
                st.push(r);
            }
            else if(ch=="-")
            {
                 x2=st.top();
                 st.pop();
                 x1=st.top();
                 st.pop();
                r=x1-x2;
                st.push(r);
            }
            else if(ch=="*")
            {
                 x2=st.top();
                 st.pop();
                 x1=st.top();
                 st.pop();
                r=x1*x2;
                st.push(r);
            }
            else if(ch=="/")
            {
                 x2=st.top();
                 st.pop();
                 x1=st.top();
                 st.pop();
                r=x1/x2;
                st.push(r);
            }
             else
             {
                 st.push(stoi(ch));
             }
        }
        return st.top();
    }
};

Solution 2 :
class Solution {
public:
    bool isOperator(const string& s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    int performOperation(int x1, int x2,const string& op) {
        if (op == "+") {
            return x1 + x2;
        } else if (op == "-") {
            return x1 - x2;
        } else if (op == "*") {
            return x1 * x2;
        } else if (op == "/") {
            return x1 / x2;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x1,x2,r;
        for(string str:tokens)
        {
            if (isOperator(str)) {
                int x2 = st.top();
                st.pop();
                int x1 = st.top();
                st.pop();
                int result =performOperation(x1, x2, str);
                st.push(result);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
