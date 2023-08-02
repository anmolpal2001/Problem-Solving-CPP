Ques : https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958

Solution : 
vector<int> moveZeros(int n, vector<int> a) {
    int cnt=0;
    for(int i=0;i<n;i++)
    {
      if (a[i] != 0) {
        swap(a[i], a[cnt]);
        cnt++;
      }
    }
    return a;
}
