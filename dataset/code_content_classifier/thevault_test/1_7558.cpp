void DijkstraPlanner(int s, vector<vector<int> > &links, vector<int> &path) {
  int n = links.size();
  
  vector<bool> visited(n, false);
  vector<int> dist(n, INT_MAX);
  
  for(int i = 0; i < n; i++) {
    path[i] = i;
  }
  
  dist[s] = 0; // starting point
  for(int i = 0; i < n; i++) {
    int u = -1;
    int min = INT_MAX;
    for(int j = 0; j < n; j++) {
      if(!visited[j] && dist[j] < min) {
	u = j;
	min = dist[j];
      }
    }

    if(u == -1) {
      return;
    }
    
    visited[u] = true;
    for(int v = 0; v < n; v++) {
      if(!visited[v] && dist[u] + links[u][v] < dist[v]) {
	dist[v] = dist[u] + links[u][v];
	path[v] = u;
      }
    }
  }
}