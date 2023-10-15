Ques : https://www.codingninjas.com/studio/problems/palindrome-number_624662

Solution : 
bool palindrome(int n)
{
    int temp=n;
    int rev=0;
    while(temp>0){
       int rem=temp%10;
        rev=(rev*10)+rem;
        temp=temp/10;
    }
    if(rev==n){
        return true;
    }
    else{
        return false;
    }
}
