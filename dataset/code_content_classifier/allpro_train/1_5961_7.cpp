#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<set>
#include<cstdio>
#include<cassert>

using namespace std;

#define foreach(i,o) for(__typeof((o).begin()) i = (o).begin(); i != (o).end(); ++i)

const int max_place = 101;
const int max_time = 601;
const int MAX_V = 2010;
const int inf = 1<<28;

struct edge{
  int src, dst;
  int cost;
  edge(int src, int dst, int cost):src(src), dst(dst), cost(cost){}
};

struct state{
  int pos;
  int prev;
  int cost;
  
  state(int pos, int prev, int cost):pos(pos),prev(prev),cost(cost){}

  bool operator>(const state &t)const{
    if(cost!=t.cost)return cost>t.cost;
    if(prev!=t.prev)return prev>t.prev;
    if(pos!=t.pos)return pos>t.pos;
    return false;
  }
};

typedef vector<edge> edges;
typedef vector<edges> graph;

int convTime(const string &s){
  int h = atoi(s.substr(0,2).c_str());
  int m = atoi(s.substr(3,2).c_str());
  return 60 * h + m;
}

string revTime(int t){
  char buf[32];
  sprintf(buf, "%02d:%02d", t/60, t%60);
  return string(buf);
}

static int dist[MAX_V][MAX_V];
void johnson(const graph &tmp_g){
  graph g = tmp_g;
  
  const int v = g.size();
  static int h[MAX_V];
  static int prev[MAX_V][MAX_V];
  

  for(int i = 0; i < v; ++i){
    h[i] = 0;
  }

  for(int i = 0; i <= v; ++i){
    bool end = true;
    for(int j = 0; j < v; ++j){
      for(int k = 0; k < (int)g[j].size(); ++k){
        edge e = g[j][k];
        int tmp = h[j] + e.cost;
        if( h[e.dst] > tmp ){
          h[e.dst] = tmp;
          end = false;
        }
      }
    }
    if(end)break;
    // do not detect an negative cycle.
  }

  for(int i = 0; i < v; ++i){
    for(int j = 0; j < v; ++j){
      dist[i][j] = inf;
      prev[i][j] = -1;
    }
    dist[i][i] = 0;
  }

  for(int i = 0; i < v; ++i){
    for(int j = 0; j < (int)g[i].size(); ++j){
      g[i][j].cost += h[i] - h[g[i][j].dst];
    }
  }

  for(int s = 0; s < v; ++s){
    priority_queue<state, vector<state>, greater<state> > q;
    q.push(state(s,s,0));
    while(!q.empty()){
      state cur = q.top(); q.pop();
      if(prev[s][cur.pos]!=-1)continue;
      prev[s][cur.pos] = cur.prev;
      for(int i = 0; i < (int)g[cur.pos].size(); ++i){
        edge e = g[cur.pos][i];
        int cost = cur.cost + e.cost;
        assert(cost>=0);
        if(dist[s][e.dst] > cost){
          dist[s][e.dst] = cost;
          q.push(state(e.dst,cur.pos,cost));
        }
      }
    }
    for(int i = 0; i < v; ++i){
      dist[s][i] += h[i] - h[s];
    }
  }

  return ;  
}

int main()
{
  int n;
  while(cin>>n && n){
    int id = 1;
    int vid = 0;
    map<string,int> cityDict;
    map<int,string> revCityDict;
    set<int> cityEvTimes[max_place];
    graph g(MAX_V);
    
    map<pair<int,int>, int> vID;
    map<int,pair<int,int> > revID;
    
    for(int i = 0; i < n; ++i){
      string from, ftime, to, ttime;
      int cost;

      cin >> from >> ftime >> to >> ttime >> cost;
      if(!cityDict.count(from)){
        cityDict[from] = id;
        revCityDict[id] = from;
        ++id;
      }
      if(!cityDict.count(to)){
        cityDict[to] = id;
        revCityDict[id] = to;
        ++id;
      }

      int src = cityDict[from];
      int dst = cityDict[to];
      int srcTime = convTime(ftime) - 480;
      int dstTime = convTime(ttime) - 480;
      
      if( dstTime >= 0 && dstTime < max_time && srcTime >= 0 && srcTime < max_time ){
        if( !vID.count(make_pair(src,srcTime)) ){
          vID[make_pair(src,srcTime)] = vid;
          revID[vid] = make_pair(src,srcTime);
          ++vid;
        }
        cityEvTimes[src].insert(srcTime);
        if( !vID.count(make_pair(dst,dstTime)) ){
          vID[make_pair(dst,dstTime)] = vid;
          revID[vid] = make_pair(dst,dstTime);
          ++vid;
        }
        cityEvTimes[dst].insert(dstTime);
        
        g[vID[make_pair(src,srcTime)]].push_back( edge(vID[make_pair(src,srcTime)], vID[make_pair(dst,dstTime)], cost) );
      }

    }
    g.resize(vID.size());
    
    for(int i = 1; i < id; ++i){
      foreach(it2, cityEvTimes[i]){
        set<int>::iterator it3 = it2;
        ++it3;
        if( it3 != cityEvTimes[i].end() ){
          g[vID[make_pair(i,*it2)]].push_back( edge(vID[make_pair(i,*it2)], vID[make_pair(i,*it3)], 0) );
        }
      }
    }
    
    johnson(g);

    int res = inf;
    int kenInitial = cityDict["Tokyo"];
    int keikoInitial = cityDict["Hakodate"];

    int ken_st, keiko_st;
    if( cityEvTimes[kenInitial].size() > 0 && cityEvTimes[keikoInitial].size() > 0 ){
      ken_st = vID[make_pair(kenInitial, *(cityEvTimes[kenInitial].begin()))];
      keiko_st = vID[make_pair(keikoInitial, *(cityEvTimes[keikoInitial].begin()))];

      for(int i = 1; i < id; ++i){
        foreach(ev1, cityEvTimes[i]){
          int v1 = vID[make_pair(i,*ev1)];
          foreach(ev2, cityEvTimes[i]){
            int v2 = vID[make_pair(i,*ev2)];
            int st = max(*ev1, *ev2) + 30;
            int from = -1;

            if(cityEvTimes[i].lower_bound(st)!=cityEvTimes[i].end()){
              from = vID[make_pair(i,*(cityEvTimes[i].lower_bound(st)))];
            }
            if(from<0)continue;
            foreach(ev3, cityEvTimes[kenInitial]){
              if( *ev3 < st ) continue;
              int v3 = vID[make_pair(kenInitial,*ev3)];
              foreach(ev4, cityEvTimes[keikoInitial]){
                if( *ev4 < st ) continue;
                int v4 = vID[make_pair(keikoInitial, *ev4)];
                res = min(res, dist[ken_st][v1] + dist[keiko_st][v2] + dist[from][v3] + dist[from][v4]);
              }
            }
          }
        }
      }
      
    }
 

    if(res>=inf)res = 0;
    cout << res << endl;
  }
  return 0;
}