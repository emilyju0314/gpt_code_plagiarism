#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef pair<int, int> P;
const int MAX_V = 105;
const int INF = 1e9;

void visit(int V, int G[MAX_V][MAX_V], int v, int s, int r,
    vector<int> &no, vector< vector<int> > &comp,
    vector<int> &prev, vector< vector<int> > &next,
    vector<int> &mcost, vector<int> &mark,
    int &cost, bool &found) {
  if (mark[v]) {
    vector<int> temp = no;
    found = true;
    do {
      cost += mcost[v];
      v = prev[v];
      if (v != s) {
        while (comp[v].size() > 0) {
          no[comp[v].back()] = s;
          comp[s].push_back(comp[v].back());
          comp[v].pop_back();
        }
      }
    } while (v != s);
    REP(i, V){
      if(i != r && no[i] == s)
        REP(j, V){
          if (no[j] != s && G[j][i] < INF) G[j][i] -= mcost[temp[i]];
        }
    }
  }
  mark[v] = true;
  REP(i, next[v].size())
    if(no[next[v][i]] != no[v] && prev[no[next[v][i]]] == v)
      if (!mark[no[next[v][i]]] || next[v][i] == s)
        visit(V, G, next[v][i], s, r, no, comp, prev, next, mcost, mark, cost, found);

}

int minimumSpanningArborescence(int V, int E, int G[MAX_V][MAX_V], int r) {
  vector<int> no(V);
  vector< vector<int> > comp(V);
  REP(i, V) comp[i].push_back(no[i] = i);

  for(int cost = 0; ;) {
    //cout <<"================================" <<endl;
    //cout <<"cost = " <<cost <<endl;
    vector<int> prev(V, -1);
    vector<int> mcost(V, INF);

    //cout <<"comp ------------------" <<endl;
    //REP(i, V){
    //  cout <<i <<": ";
    //  REP(j, comp[i].size()) cout <<comp[i][j] <<", ";
    //  cout <<endl;
    //}
    //cout <<"no ------------------" <<endl;
    //REP(i, V) cout <<i <<": " <<no[i] <<endl;

    REP(i, V){
      REP(j, V){
        if(j == r || G[i][j] == INF || no[i] == no[j] || G[i][j] > mcost[no[j]]) continue;
        mcost[no[j]] = G[i][j];
        prev[no[j]] = no[i];
      }
    }
    //cout <<"mcost ------------------" <<endl;
    //REP(i, V) cout <<i <<": " <<mcost[i] <<endl;
    //cout <<"prev ------------------" <<endl;
    //REP(i, V) cout <<i <<": " <<prev[i] <<endl;

    vector< vector<int> > next(V);
    REP(i, V)
      if(prev[i] >= 0)
        next[prev[i]].push_back(i);

    //cout <<"next ------------------" <<endl;
    //REP(i, V){
    //  cout <<i <<": ";
    //  REP(j, next[i].size()) cout <<next[i][j] <<", ";
    //  cout <<endl;
    //}

    bool stop = true;
    vector<int> mark(V, false);
    REP(i, V)
      if(i != r && !mark[i] && !comp[i].empty()) {
        bool found = false;
        visit(V, G, i, i, r, no, comp, prev, next, mcost, mark, cost, found);
        if (found) stop = false;
      }
    if (stop) {
      REP(i, V) if (prev[i] >= 0) cost += mcost[i];
      return cost;
    }
  }
}

int main() {
  int V, E, r;
  cin >>V >>E >>r;
  int G[MAX_V][MAX_V];
  REP(i, V) REP(j, V) G[i][j] = (i == j ? 0 : INF);
  REP(i, E){
    int f, t, c; cin >>f >>t >>c;
    G[f][t] = c;
  }
  cout <<minimumSpanningArborescence(V, E, G, r) <<endl;
  return 0;
}