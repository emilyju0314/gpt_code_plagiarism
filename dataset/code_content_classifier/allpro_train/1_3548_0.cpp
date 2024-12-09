# include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef vector<int> vi;
 
// uf
int data[1252];
void init(int n){
  REP(i,n)data[i]=-1;
}
int root(int x){
  return data[x]<0?x:(data[x]=root(data[x]));
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x!=y){
    if(data[x]>data[y])swap(x,y);
    data[x]+=data[y];
    data[y]=x;
  }
}
 
vi calcinfo(vi args){
  unordered_map<int,int> id;
  int tail = 0;
  vi ret = vi(args.size(),0);
  REP(i,args.size()){
    int x = args[i];
    if(!id.count(root(x))){
      id[root(x)] = tail++;
    }
    ret[i] = id[root(x)];
  }
  return ret;
}
 
int n,m;
char maze[1252][25][21];
char tmp[25][21];
vi mazeinfo[1252][4];
 
int main(){
  while(true){
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)break;
    REP(i,m){
      REP(j,n)scanf("%s",maze[i][j]);
    }
    // cerr << "[!] n=" << n << ", m=" << m << endl;
    // n=1
    if(n==1){
      // cerr << "[n==1]" << endl;
      bool ok = true;
      REP(i,m)if(maze[i][0][0]=='#'){
        ok = false;
      }
      puts(ok?"Yes":"No");
      continue;
    }
    // calc mazeinfo
    REP(i,m)REP(rot,4){
      init(n*n);
      REP(j,n)REP(k,n){
        if(maze[i][j][k]!='.')continue;
        if(j<n-1 && maze[i][j+1][k]=='.'){
          unite(j*n+k, (j+1)*n+k);
        }
        if(k<n-1 && maze[i][j][k+1]=='.'){
          unite(j*n+k, j*n+(k+1));
        }
      }
      vi arg;
      REP(x,n)arg.push_back(x*n);
      REP(x,n)arg.push_back(x*n+n-1);
      vi info = calcinfo(arg);
      mazeinfo[i][rot] = info;
      // rotate
      REP(j,n)REP(k,n)tmp[j][k] = maze[i][k][n-1-j];
      REP(j,n)REP(k,n)maze[i][j][k] = tmp[j][k];
    }
    // cerr << "[!] mazeinfo calc end" << endl;
    // dp
    set<vi> S,T;
    S.insert(vi(2*n,0));
    vi infoget;
    REP(i,n)infoget.push_back(i);
    REP(i,n)infoget.push_back(i+2*n);
    REP(i,m){
      T.clear();
      // cerr << "[dp] step=" << i << ", |state|=" << S.size() << endl;
      for(vi V : S){
        REP(r,4){
          vi U = mazeinfo[i][r];
          init(3*n);
          vi id;
          REP(j,2*n){
            if(id.size()==V[j]){
              id.push_back(j);
            }else{
              unite(j,id[V[j]]);
            }
          }
          id.clear();
          REP(j,2*n){
            if(id.size()==U[j]){
              id.push_back(j+n);
            }else{
              unite(j+n,id[U[j]]);
            }
          }
          set<int> sleft;
          REP(j,n)sleft.insert(root(j));
          bool ok = false;
          REP(j,n)if(sleft.count(root(j+2*n))){
            ok = true;
          }
          if(ok){
            T.insert(calcinfo(infoget));
          }
        }
      }
      swap(S,T);
    }
    if(S.size()){
      puts("Yes");
    }else{
      puts("No");
    }
  }
}