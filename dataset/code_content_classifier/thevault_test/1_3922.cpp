void dfsrec2(vector<int>adj[] , int s , vector<bool>&visited){
    visited[s]=true;
    cout<<s<<" ";
    for(int u : adj[s]){
        if(visited[u]==false){
            dfsrec2(adj , u , visited);
        }
    }
}