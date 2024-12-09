#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#define rep(i,a) for(int i=0;i<(int)(a);i++)
#define INIT(a) memset(a,0,sizeof(a))
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> P;
const int INF = 1e9+7;

int v;
P seg[303000];

inline void init(int n){
  v = 1;
  while(v<n)v<<=1;
  rep(i,2*v-1)seg[i] = P(INF,INF);
}

inline void update(int x, P a){
  x += v-1;
  seg[x] = a;
  while(x){
    x = (x-1)>>1;
    seg[x] = min(seg[2*x+1],seg[2*x+2]);
  }
}

inline P query(int a, int b, int k ,int l, int r){
  if(b<=l || r<=a)return P(INF,INF);
  if(a<=l && r<=b)return seg[k];
  P ql = query(a,b,2*k+1,l,(l+r)/2);
  P qr = query(a,b,2*k+2,(l+r)/2,r);
  return min(ql,qr);
}

int n,r,l;
int d,t,x,prv=0;
int len[100100];

int main(){
  INIT(len);
  scanf("%d%d%d",&n,&r,&l);
  init(n);
  rep(i,n)update(i,P(0,i));

  rep(i,r){
    scanf("%d%d%d",&d,&t,&x);
    P tmp = query(0,n,0,0,v);
    len[tmp.sc] += t-prv;
    prv = t;
    update(d-1,P(seg[d-1 +v-1].fs-x,d-1));
  }
  len[query(0,n,0,0,v).sc] += l-prv;

  int ans = 0;
  rep(i,n){
    if(len[ans] < len[i])ans = i;
  }
  printf("%d\n",ans+1);
}