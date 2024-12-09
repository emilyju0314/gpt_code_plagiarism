bool reduce(int n, int lim, vector <pair<int, int> >& edge){
    bitset <202> adj[n + 1]; /// Maximum value for n
    while (lim--){
        vector <pair<int, int> > temp = edge;
        random_shuffle(temp.begin(), temp.end());

        for (int i = 1; i <= n; i++){
            adj[i].reset();
            adj[i][i] = true;
        }

        edge.clear();
        int len = temp.size();
        for (int e = 0; e < len; e++){
            int i = temp[e].first, j = temp[e].second;
            if (!adj[i][j]){
                edge.push_back(temp[e]);
                if (adj[j][i]) return false;

                for (int k = 1; k <= n; k++){
                    if (adj[k][i]) adj[k] |= adj[j];
                }
            }
        }

        if (edge.size() == temp.size()) return true;
    }
    return true;
}