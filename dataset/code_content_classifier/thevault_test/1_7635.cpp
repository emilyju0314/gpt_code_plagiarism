void eulerTour(int node, int parent, int cost){
    in[node] = ++dfsCnt;
    ID[dfsCnt] = node;
    incomingEdge[node] = cost;
    for(int i = 0; i < (int) graph[node].size(); i++){
        pair<int, int> next = graph[node][i];
        if(next.first != parent){
            level[next.first] = level[node] + 1;
            eulerTour(next.first, node, next.second);
        }
    }
    out[node] = ++dfsCnt;
    ID[dfsCnt] = node;
}