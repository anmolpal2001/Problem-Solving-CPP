Ques : https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

Solution : 
// TC : O(1) and SC : O(1)
class SpecialStack {
    public:
    stack<int> s;
    int mini;
    void push(int data) {
       if(s.empty())
       {
           s.push(data);
           mini=data;
       }
       else
       {
           if(data<mini)
           {
               s.push(2*data-mini);
               mini=data;
           }
           else
           {
               s.push(data);
           }
       }
    }

    void pop() {
        if(!s.empty())
        {
            int curr = s.top();
            s.pop();
            if(curr<mini)
            {
                int prevMin=mini;
                int val=2*mini-curr;
                mini=val;
            }    
        }
    }

    int top() {
        if(s.empty())
        {
            return -1;
        }
        int curr=s.top();
        if(curr<mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin() {
       if(s.empty())
       {
           return -1;
       }
       return mini;
    }  
};
