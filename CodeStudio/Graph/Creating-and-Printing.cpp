Ques : https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551

Solution : 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
   vector<vector<int>> adj(n);
    for(int i=0; i<n; ++i){
            adj[i].push_back(i); 
    }
    
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
