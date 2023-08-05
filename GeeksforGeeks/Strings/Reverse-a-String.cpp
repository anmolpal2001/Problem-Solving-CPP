// Question : https://practice.geeksforgeeks.org/problems/reverse-a-string/1

Solution 1 : 
string reverseWord(string str){
    
  //Your code here
  int len = str.length();
  int start = 0;
  for(int i=len;i>=start;i--)
  {
      cout<<str[i];
  }
}

Solution 2 :
string reverseWord(string str){
    
  //Your code here
  int s=0;
  int e=str.length()-1;
  while(s<=e)
  {
      swap(str[s++],str[e--]);
  }
  return str;
}
