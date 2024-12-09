#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;

const int INF = 1<<29;

typedef pair<int,int> P;

class State{
public:
  int cost,node,x,y,dir,now;

  State(int c, int n, int _x, int _y, int d, int n2){
    cost = c;
    node = n;
    x = _x;
    y = _y;
    dir = d;
    now = n2;
  }

  bool operator < (const State& s) const {
    if(cost == s.cost) return node > s.node;
    return cost > s.cost;
  }
};

int V,E;
vector<int> G[1001];
vector<P>v;
P d[1001][4];

void dijkstra(int s){
  priority_queue<State>que;
  int X = v[s].first, Y = v[s].second;
  for(int i=0; i<4; i++){
    State t(0,1,X,Y,i,s);
    d[s][i].first = d[s][i].second = 0;
    que.push(t);
  }

  while(!que.empty()){
    State tmp = que.top();
    que.pop();
    int cost = tmp.cost;
    int x = tmp.x, y = tmp.y;
    int node = tmp.node;
    int dir = tmp.dir;
    int now = tmp.now;

    if(d[now][dir].first < cost) continue;

    for(int i=0; i<G[now].size(); i++){
      int index = G[now][i];
      int nx = v[index].first, ny = v[index].second;
      if(dir == 0 && y == ny && x > nx){
	if(d[index][3].first >= cost + x - nx){
	  d[index][3].first = cost + x - nx;
	  d[index][3].second = min(d[index][3].second,node + 1);
	  que.push(State(d[index][3].first,d[index][3].second,nx,ny,3,index));
	}
      }

      if(dir == 1 && x == nx && y < ny){
	if(d[index][0].first >= cost + ny - y){
	  d[index][0].first = cost + ny - y;
	  d[index][0].second = min(d[index][0].second,node + 1);
	  que.push(State(d[index][0].first,d[index][0].second,nx,ny,0,index));
	}
      }

      if(dir == 2 && y == ny && x < nx){

	if(d[index][1].first >= cost + nx - x){
	  d[index][1].first = cost + nx - x;
	  d[index][1].second = min(d[index][1].second,node + 1);
	  que.push(State(d[index][1].first,d[index][1].second,nx,ny,1,index));
	}
      }

      if(dir == 3 && x == nx && y > ny){
	if(d[index][2].first >= cost + y - ny){
	  d[index][2].first = cost + y - ny;
	  d[index][2].second = min(d[index][2].second,node + 1);
	  que.push(State(d[index][2].first,d[index][2].second,nx,ny,2,index));
	}
      }


      //straight

      if(dir == 0 && nx == x && ny > y){
	if(d[index][dir].first >= cost + ny - y){
	  d[index][dir].first = cost + ny - y;
	  d[index][dir].second = min(d[index][dir].second,node + 1);
	  que.push(State(d[index][dir].first,d[index][dir].second,nx,ny,dir,index));
	}
      }

      if(dir == 1 && ny == y && nx > x){
	if(d[index][dir].first >= cost + nx - x){
	  d[index][dir].first = cost + nx - x;
	  d[index][dir].second = min(d[index][dir].second,node + 1);
	  que.push(State(d[index][dir].first,d[index][dir].second,nx,ny,dir,index));
	}
      }
      
      if(dir == 2 && nx == x && ny < y){
	if(d[index][dir].first >= cost + y - ny){
	  d[index][dir].first = cost + y - ny;
	  d[index][dir].second = min(d[index][dir].second,node + 1);
	  que.push(State(d[index][dir].first,d[index][dir].second,nx,ny,dir,index));
	}
      }
      
      if(dir == 3 && ny == y && nx < x){
	if(d[index][dir].first >= cost + x - nx){
	  d[index][dir].first = cost + x - nx;
	  d[index][dir].second = min(d[index][dir].second,node + 1);
	  que.push(State(d[index][dir].first,d[index][dir].second,nx,ny,dir,index));
	}

      }

    }
  }
}
int main(){

  while(cin >> V >> E,V|E){

    for(int i=0; i<1001; i++)
      for(int j=0; j<4; j++) d[i][j].first = d[i][j].second = INF;

    for(int i=0; i<1001; i++)G[i].clear();
    v.clear();

    string s;
    int x,y;
    map<string,int>m;
    for(int i=0; i<V; i++){
      cin >> s >> x >> y;
      v.push_back(P(x,y));
      m[s] = i;
    }

    string from,to;
    for(int i=0; i<E; i++){
      cin >> from >> to;
      G[m[from]].push_back(m[to]);
      G[m[to]].push_back(m[from]);
    }

    string start,des;
    cin >> start >> des;

    dijkstra(m[start]);

    int MinCost = INF, ans = INF;

    for(int i=0; i<4; i++){
      if(MinCost > d[m[des]][i].first){
	MinCost = d[m[des]][i].first;
	ans = d[m[des]][i].second;
      } else if(MinCost == d[m[des]][i].first){
	ans = min(ans,d[m[des]][i].second);
      }
    }

    if(MinCost == INF) cout << "impossible" << endl;
    else cout << ans << endl;
  }
  return 0;
}