#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;

struct edge {
  int to, cost;
};

int Dijkstra(vector< vector< edge > >& info, int s, int g) { //sからgへの最短路
  typedef pair< int, int > Pi;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  vector< int > min_cost;
  min_cost.resize(info.size(), -1);
  que.push( Pi( 0, s));
  min_cost[s] = 0;
  while(!que.empty()){
    Pi p = que.top(); que.pop();
    if(p.second == g) return p.first;
    if(p.first > min_cost[p.second]) continue;
    for(int i = 0; i < info[p.second].size(); i++){
      edge& e = info[p.second][i];
      if(min_cost[e.to] == -1 || p.first + e.cost < min_cost[e.to]){
        min_cost[e.to] = p.first + e.cost;
        que.push( Pi( min_cost[e.to], e.to));
      }
    }
  }
  return -1;
}

int main()
{
  int n;
  while(cin >> n, n) {
    vector< int > a(n), b(n);
    vector< vector< edge > > graph(2 * n + 2);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }

    int Start = 2 * n;
    int Goal  = 2 * n + 1;
    graph[Start].push_back((edge){0, 0});
    graph[Start].push_back((edge){1, 0});
    if(a[n - 1] != 2) graph[n * 2 - 2].push_back((edge){Goal, 0});
    if(b[n - 1] != 2) graph[n * 2 - 1].push_back((edge){Goal, 0});

    for(int i = 0; i < n; i++) {
      if(a[i] == 2) {
        graph[i * 2].push_back((edge){i * 2 - 2, 0});
      } else if(a[i] == 0 || (a[i] == 1 && a[i + 1] != 1)) {
        for(int j = i; j < min(n, i + 3); j++) {
          graph[i * 2].push_back((edge){j * 2 + 1, 1});
        }
      } else {
        graph[i * 2].push_back((edge){i * 2 + 2, 0});
      }

      if(b[i] == 2) {
        graph[i * 2 + 1].push_back((edge){i * 2 - 1, 0});
      } else if(b[i] == 0 || (b[i] == 1 && b[i + 1] != 1)) {
        for(int j = i; j < min(n, i + 3); j++) {
          graph[i * 2 + 1].push_back((edge){j * 2, 1});
        }
      } else {
        graph[i * 2 + 1].push_back((edge){i * 2 + 3, 0});
      }
    }
    int ret = Dijkstra(graph, Start, Goal);
    if(~ret) cout << ret << endl;
    else cout << "NA" << endl;
  }
}