ll kruskal(int nodeAmount, vector<Edge> &ed, vector<vector<int>> &result){
    ll cost = 0;
    DSUFast dsu(nodeAmount);
    sort(ed.begin(), ed.end());
    result.assign(nodeAmount, vector<int>());

    for(Edge e : ed)
        if(dsu.find(e.u) != dsu.find(e.v)){
            cost += e.weight;
            result[e.u].pb(e.v);
            result[e.v].pb(e.u);
            dsu.join(e.u, e.v);
        }

    return cost;
}