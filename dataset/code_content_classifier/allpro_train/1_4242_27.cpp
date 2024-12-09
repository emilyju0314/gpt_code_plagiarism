#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N = 1e5+5;
struct Man{
   int a,b;
   bool operator<(const Man &rhs)const{
      return a-b>rhs.a-rhs.b;
   }
}s[N];
int n,c[N],l,ma[N],b[N];
priority_queue<pii>q;
set<pii>se;
int solve(){
  ll up=0,down=0;
  for(int i=1;i<=n;++i){
     if(up+ma[i]>=l)return i;
     up+=s[i].a-s[i].b;
     ll tmp = up-down;
     while(!q.empty()&&q.top().first>=tmp){
         int x = q.top().second;
         q.pop();
         se.erase(make_pair(s[x].b,x));
     }
     if(!se.empty()&&up+(*--se.end()).first>=l)return i;
     down+=c[i];
     if(up<=down)break;
     se.insert(make_pair(s[i].b,i));
     q.push(make_pair(s[i].a-s[i].b,i));
  }
  return -1;
}
int main() {
   scanf("%d%d",&n,&l);
   for(int i=1;i<=n;++i){
      scanf("%d%d",&s[i].a,&s[i].b);
   }
   for(int i=1;i<=n;++i)scanf("%d",&c[i]);
   sort(s+1,s+1+n);
   for(int i=n;i>=1;--i)ma[i]=max(ma[i+1],s[i].a);
   printf("%d\n",solve());
   return 0;
}