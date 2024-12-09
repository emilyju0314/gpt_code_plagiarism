#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>


#define reps(i,f,n) for(int i = f; i <= n; ++i)
#define rep(i,n) reps(i, 0, n-1)

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIP;

class edge{
  public:
  int to;
  int cost;
  int ti;
  int ad;
  edge(int a,int b, int c, int d):to(a), cost(b), ti(c), ad(d){};
};

const int INF = 1e8;

int n, m, H, k;
int d[(1<<8)+1];
int s, t;
int kj;
int G[128][32];
int states[1<<8];
int used[1<<8];
int used2[128][32];
int ans;
vector<edge> e[128];
vector<int> pass;

void init(){
  rep(i,32)rep(j,128)G[j][i] = INF;
  rep(i,32)rep(j,128)used2[j][i] = 0;
  rep(i,(1<<8))states[i] = INF;
  rep(i,(1<<8))d[i] = -1;
  rep(i,(1<<8))used[i] = 0;
  rep(i,128)e[i].clear();
  pass.clear();
  ans = INF;
}

void c_state_cost(){
  priority_queue<PII, vector<PII>, greater<PII> > p;
  //state
  p.push(PII(0,0));
  states[0] = 0;

  while(!p.empty()){
    int cost = p.top().first;
    int state = p.top().second;p.pop();
    if(used[state])continue;
    used[state] = 1;
    rep(i,(int)pass.size()){
      int n_state = state | pass[i];
      if( states[n_state] > states[state] + d[i]){
        states[n_state] = states[state] + d[i];
        p.push(PII(states[n_state], n_state));
      }
    }
  }
}

void dijkstra(){
  ans = INF;
  rep(state, (1<<k)){
    if(states[state] == INF) continue;
    // cout << "state " << state << endl;
    rep(i,32)rep(j,128)G[j][i] = INF;
    rep(i,32)rep(j,128)used2[j][i] = 0;

    priority_queue<PIP, vector<PIP>, greater<PIP> > q;
    //cost , hour , pos 
    q.push(PIP(states[state],PII(0, s)));
    G[s][0] = states[state];
    while(!q.empty()){
      int cost = q.top().first;
      int hour = q.top().second.first;
      int pos = q.top().second.second;q.pop();
      // cout << ":cost " << cost << "  :hour " << hour << " :pos  " << pos << endl;

      if(used2[pos][hour])continue;
      used2[pos][hour] = 1;
      if(pos == t){ans = min(ans,cost);break;}
      rep(i,e[pos].size()){
        int to = e[pos][i].to;
        int co = e[pos][i].cost;
        int hou = e[pos][i].ti;
        int n_hour = hour + hou;
        // cout << to << ":" << co << ":" << hou << ":" << endl;
        if((state & (1<<e[pos][i].ad)) > 0) co = 0;
        if(hour+hou > H)continue;
        if(G[to][n_hour] > G[pos][hour] + co){
          G[to][n_hour] = G[pos][hour] + co;
          q.push(PIP(G[to][n_hour], PII(n_hour, to)));
        }
      }
    }
  }
}

int main(){
  int l;
  int a,b,c,h,r,p;
  while(1){
    init();
    cin >> n >> m >> H >> k;
    if( n == 0 && m == 0)break;
    rep(i,m){
      cin >> a >> b >> c >> h >> r;
      a--;b--;r--;
      e[a].emplace_back(edge(b,c,h,r));
      e[b].emplace_back(edge(a,c,h,r));
    }

    cin >> s >> t >> p;
    s--;t--;
    rep(i,p){
      int pa = 0;
      cin >> l >> d[i];
      rep(j,l){
        cin >> kj;
        kj--;
        pa |= 1<<kj;
      }
      pass.push_back(pa);
    }
    c_state_cost();
    dijkstra();
    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;
  }

  return 0;
}