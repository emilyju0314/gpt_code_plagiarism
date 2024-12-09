#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q, s;
    cin >> n >> q >> s;
    
    vector<vector<pair<int, int>>> portals(n+1);
    
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        
        if(t == 1){
            int v, u, w;
            cin >> v >> u >> w;
            portals[u].push_back(make_pair(v, w));
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            for(int j=l; j<=r; j++){
                portals[j].push_back(make_pair(v, w));
            }
        }
    }
    
    vector<int> minCost(n+1, INT_MAX);
    minCost[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        int currCost = pq.top().first;
        int currPlanet = pq.top().second;
        pq.pop();
        
        for(pair<int, int> p: portals[currPlanet]){
            int nextPlanet = p.first;
            int cost = p.second;
            
            if(minCost[nextPlanet] > currCost + cost){
                minCost[nextPlanet] = currCost + cost;
                pq.push(make_pair(minCost[nextPlanet], nextPlanet));
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(minCost[i] == INT_MAX){
            cout << -1 << " ";
        } else {
            cout << minCost[i] << " ";
        }
    }
    
    return 0;
}