Ques : https://www.codingninjas.com/studio/problems/delete-middle-element-from-stack_985246

Solution 1 : 
// TC : O(N) and SC : O(N)
void deleteMiddle(stack<int>&inputStack, int N){
   stack<int> buffer;
   for(int i=0;i<N/2;i++)
   {
      buffer.push(inputStack.top());
      inputStack.pop();
   }
   inputStack.pop();
   while(!buffer.empty())
   {
      inputStack.push(buffer.top());
      buffer.pop();
   }
}

Solution 2 :
// TC : O(N) and SC : O(N)
void solve(stack<int>&inputStack,int count, int size)
{
   if(count==size/2)
   {
      inputStack.pop();
      return;
   }
   int num=inputStack.top();
   inputStack.pop();
   solve(inputStack,count+1,size);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
   int count=0;
   solve(inputStack,count,N);
}
