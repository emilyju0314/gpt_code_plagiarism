inline void addEdge(int a, int b, long long c){
        adj[a].push_back(E.size());
        E.push_back(Edge(a, b, c, 0));
        len[a]++;
        adj[b].push_back(E.size());
        E.push_back(Edge(b, a, 0, 0));
        len[b]++;
    }