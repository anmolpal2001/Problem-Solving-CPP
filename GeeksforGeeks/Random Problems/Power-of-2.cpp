Ques : https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/0

Solution : 
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        return (n<1)?0:!(n&(n-1));
    }
};
