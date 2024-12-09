#include<iostream>
#include<queue>
#include<map>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
typedef long long ll;
const ll mod = 1000000009;
const int N = 200000;

int deg[N];
int size[N];
bool isdel[N];
int f[N],t[N];

int main(){
  int n,m;
  while(cin>>n>>m){
    ll ans=0,num=1;
    rep(i,n)isdel[i]=false,deg[i]=0,size[i]=1;
    rep(i,m){
      cin>>f[i]>>t[i];
      f[i]--;t[i]--;
      deg[f[i]]++;
      deg[t[i]]++;
      if (f[i] > t[i])swap(f[i],t[i]);
    }
    rep(i,m){
      int &now=f[i],&next=t[i];//now < next
      if (deg[now] > deg[next])isdel[now]=true;
      else if (deg[now] == deg[next])isdel[next]=true,size[now]++;
      else if (deg[now] < deg[next])isdel[next]=true;
    }
    rep(i,n){
      if (isdel[i])continue;
      else ans++,num=(num*size[i])%mod;
    }
    cout << ans <<endl << num<<endl;
#ifdef DEBUG
    cout << "end"<< endl;
#endif
  }
}