#include<bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

struct Primal_Dual
{
  typedef pair< int, int > Pi;
 
  struct edge
  {
    int to, cap, cost, rev;
  };
  vector< vector< edge > > graph;
  vector< int > potential, min_cost, prevv, preve;
 
  Primal_Dual(int V):graph(V){}
 
  void add_edge(int from, int to, int cap, int cost)
  {
    graph[from].push_back((edge){to, cap, cost, (int)graph[to].size()});
    graph[to].push_back((edge){from, 0, -cost, (int)graph[from].size() - 1});
  }
 
  int min_cost_flow(int s,int t,int f)
  {
    
    int V = graph.size(), ret = 0;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, 0);
    prevv.assign(V, -1);
    preve.assign(V, -1);

    while(f > 0){
      min_cost.assign(V, INF);

      que.push(Pi(0, s));
      min_cost[s] = 0;
      while(!que.empty()){
        Pi p = que.top(); que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++){
          edge& e = graph[p.second][i];
          int nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost){
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.push(Pi(min_cost[e.to], e.to));

          }
        }
      }

      if(min_cost[t] == INF) return -1;
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      int addflow = f;
      for(int v = t; v != s; v = prevv[v]){
        addflow = min( addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]){
        edge& e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return(ret);
  }
};

struct Data
{
  int X, Y, C;
  bool operator<(const Data& e) const
  {
    return(Y < e.Y);
  }
};

int main()
{
  int N;
  while(cin >> N, N) {
    Primal_Dual MCF(N * 20 * 20);
    vector< vector< Data > > train(N);
    vector< int > nums;

    for(int i = 0; i < N - 1; i++) {
      int M;
      cin >> M;
      while(M--) {
        int x, y, c;
        cin >> x >> y >> c;
        nums.push_back(y);
        train[i + 1].push_back((Data){x, y, c});
      }
    }
    int G;
    train[0].push_back((Data){0, 0, 0});

    cin >> G;

    int ptr = 0;
    int prev = 0;
    vector< int > arras, now;
    now.push_back(0);

    for(int i = 1; i < train.size(); i++) {
      sort(train[i].begin(), train[i].end());
      int buff = ptr;
      for(int j = 0; j < train[i].size(); j++) {
        int low = 0;
        if(train[i - 1][0].Y > train[i][j].X) continue;
        for(int k = 0; k < train[i - 1].size(); k++) {
          if(train[i][j].X >= train[i - 1][k].Y) low = max(low, k);
        }
        if(j == 0 || train[i][j - 1].Y != train[i][j].Y) {
          MCF.add_edge(now[low], ++ptr, 1, train[i][j].C);
          MCF.add_edge(ptr, ptr + 1, 1, 0);
          ++ptr;
          arras.push_back(ptr);
          if(j != 0) MCF.add_edge(ptr - 2, ptr, INF, 0);
        } else {
          arras.push_back(ptr);
          MCF.add_edge(now[low], ptr - 1, 1, train[i][j].C);
        }
      }
      prev = buff;
      swap(arras, now);
      arras.clear();
    }
    int ret = 0, buff = 0, tail = 0;
    for(tail = 1; tail <= G; tail++) {
      if((buff = MCF.min_cost_flow(0, ptr, 1)) == -1) break;
      ret += buff;
    };
    cout << tail - 1 << " " << ret << endl;
  }
}