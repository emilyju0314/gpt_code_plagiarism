#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return 0&pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=2e5;
typedef int fuko[yuzu|10];
fuko u,v;int vis[2][yuzu>>6][yuzu>>6];
vector<int> lj[yuzu|10];

void dfs(int id,int p,int u,int col){
if (vis[id][p][u]) return;
vis[id][p][u]=col;
for (int i:lj[u]) dfs(id,p,i,col);
}

int main(){
int i,n=read(),m=read();
for (i=1;i<=m;++i){
  u[i]=read(),v[i]=read();
  lj[u[i]].push_back(v[i]);
  } 
for (i=1;i<=n;++i){
  vis[0][i][i]=vis[1][i][i]=1;
  int now=0;for (int j:lj[i]) dfs(0,i,j,++now);
  if (lj[i].size()) for (int j=lj[i].size()-1;~j;--j) dfs(1,i,lj[i][j],j+1);
  }
for (i=1;i<=m;++i){
  puts((vis[0][u[i]][v[i]]!=vis[1][u[i]][v[i]])^(vis[0][v[i]][u[i]]>0)?"diff":"same");
  }
}