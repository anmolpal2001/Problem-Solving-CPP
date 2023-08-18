Ques : https://leetcode.com/problems/happy-number/

Solution 1 : 
// TC : O(logN) where N is the number and SC : O(logN), Hash Table(unordered_set(set)) space.
// Solved using Math + Hash Table
class Solution {
public:
    int sqr(int n)
    {
        int ans=0;
        while(n)
        {
            int num=n%10;
            ans+=num*num;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1 && !st.count(n))
        {
            st.insert(n);
            n=sqr(n);
        } 
        return n==1;
    }
};

Solution 2 : 
// TC : O(logN) where N is the number and SC : O(1), Constant space.
// Solved using Floyd's Cycle-Finding Algorithm
class Solution {
public:
    int sqr(int n)
    {
        int ans=0;
        while(n)
        {
            int num=n%10;
            ans+=num*num;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do
        {
            slow=sqr(slow);
            fast=sqr(sqr(fast));
        }while(slow!=fast);
        return slow==1;
    }
};
