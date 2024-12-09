#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

map<char,int> m = {{'r',0}, {'m',1}, {'y',2}, {'b',3}, {'g',4}, {'c',5}};

/*
  2
1 0 4
  3
  5
*/
// ??????[0][1]
// [???][??????] -> ???
int dice[6][6] ={
  {-1, 3, 1, 4, 2,-1},
  { 2,-1, 5, 0,-1, 3},
  { 4, 0,-1,-1, 5, 1},
  { 1, 5,-1,-1, 0, 4},
  { 3,-1, 0, 5,-1, 2},
  {-1, 2, 4, 1, 3,-1}
};

bool visited[30][30][6][6][6];

int main(){
  int w,d;
  while(cin>>w>>d, w|d){
    vector<string> vec(d);
    rep(i,d) cin>>vec[i];
    string query;
    cin>>query;

    int sx=-1,sy=-1;
    rep(i,d)rep(j,w) if(vec[i][j]=='#'){
      sx=i; sy=j;
      vec[i][j] = 'w';
    }

    const int dx[] = {1,-1,0,0}, dy[]={0,0,1,-1};
    function<pair<int,int>(int,int)> df[] = { // return <top,front>
      [&](int t, int f){return mp(5-f, t);},
      [&](int t, int f){return mp(f, 5-t);},
      [&](int t, int f){return mp(5-dice[t][f], f);},
      [&](int t, int f){return mp(dice[t][f], f);}
    };

    fill(visited[0][0][0][0], visited[30][0][0][0], false);

    int ans = INF;

    using state = tuple<int,int,int,int,int,int>;
    // <s,y,top,front,level>
    queue<state> q;
    q.push((state){sx,sy,0,1,0,0});
    visited[sx][sy][0][1][0] = true;
    while(!q.empty()){
      int x,y,t,f,l,dist;
      tie(x,y,t,f,l,dist) = q.front(); q.pop();

      rep(k,4){
        int nx = x + dx[k], ny = y + dy[k];
        auto p = df[k](t,f);
        if(nx<0 || ny<0 || nx>=d || ny>=w || vec[nx][ny]=='k') continue;

        int nl = l;
        if(vec[nx][ny]!='w'){
          if(vec[nx][ny] == query[l] && p.fi == m[query[l]]) nl++;
          else continue;
          if(nl == 6){
            ans = min(ans, dist+1);
            continue;
          }
        }

        if(visited[nx][ny][p.fi][p.se][nl]) continue;

        visited[nx][ny][p.fi][p.se][nl] = true;
        q.push((state){nx, ny, p.fi, p.se, nl, dist+1}); //dbg(nx,ny,p.fi,p.se,nl,dist);
      }
    }

    if(ans>=INF) cout <<"unreachable"<<endl;
    else cout << ans << endl;
  }

  return 0;
}