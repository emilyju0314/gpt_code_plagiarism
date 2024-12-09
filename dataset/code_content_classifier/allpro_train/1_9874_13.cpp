#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

int n;
char x[125252];
int q;

typedef pair<pii,int> piii;
#define L first.first
#define R first.second
#define C second

int f=0,g=0;

int main(){
  scanf("%d",&n);
  scanf("%s",x);
  scanf("%d",&q);
  set<piii> S;
  int bef = 0;
  int head = 0;
  REP(i,n)if(x[i]-'0' != bef){
    S.insert(piii(pii(head,i-1),bef));
    bef = x[i]-'0';
    head = i;
  }
  S.insert(piii(pii(head,n-1),bef));
    // for(piii P : S){
    //   printf("%d %d %d\n",P.L,P.R,P.C);
    // }

  REP(i,n)f += x[i]-'0';
  REP(i,n-1)g += (x[i]-'0') * (x[i+1]-'0');

  while(q--){
    int l,r,b;
    scanf("%d%d%d",&l,&r,&b);
    --l;--r;
    piii add = piii(pii(l,r),b);
    // left
    {
      auto it = S.lower_bound(piii(pii(l,-1),-1));
      if(it!=S.begin()){
        --it;
        auto cell = *it;
        int cl = cell.L;
        int cr = cell.R;
        int cc = cell.C;
        if(l <= cr){
          // cross
          if(b==cc){
            // nobasu
            l = cl;
          }else{
            // cut
            if(cc==1){
              --g;
            }
            S.erase(it);
            auto cell2 = cell;
            cell.R = l-1;
            cell2.L = l;
            S.insert(cell);
            S.insert(cell2);
          }
        }
      }
    }
    // absorb
    while(true){
      auto it = S.lower_bound(piii(pii(l,-1),-1));
      if(it==S.end())break;
      if(it->R <= r){
        auto cell = *it;
        S.erase(it);
        if(cell.C == 1){
          int len = cell.R - cell.L + 1;
          f -= len;
          g -= len-1;
        }
      }else{
        break;
      }
    }
    // tail
    {
      auto it = S.lower_bound(piii(pii(l,-1),-1));
      if(it!=S.end()){
        if(it->C == b){
          if(it->C == 1){
            int len = it->R - it->L + 1;
            f -= len;
            g -= len-1;
          }
          r = it->R;
          S.erase(it);
        }else{
          if(it->C == 1){
            int len = r - it->L + 1;
            f -= len;
            g -= len;
          }
          auto cell = *it;
          cell.L = r+1;
          S.erase(it);
          S.insert(cell);
        }
      }
    }
    // head connect
    {
      auto it = S.lower_bound(piii(pii(l,-1),-1));
      if(it!=S.begin()){
        --it;
        if(it->C == b){
          l = it->L;
          if(it->C == 1){
            int len = it->R - it->L + 1;
            f -= len;
            g -= len-1;
          }
          S.erase(it);
        }
      }
    }
    // tail connect
    {
      auto it = S.lower_bound(piii(pii(l,-1),-1));
      if(it!=S.end()){
        if(it->C == b){
          r = it->R;
          if(it->C == 1){
            int len = it->R - it->L + 1;
            f -= len;
            g -= len-1;
          }
          S.erase(it);
        }
      }
    }
    S.insert(piii(pii(l,r),b));
    if(b==1){
      int len = r-l+1;
      f += len;
      g += len-1;
    }
    // for(piii P : S){
    //   printf("%d %d %d\n",P.L,P.R,P.C);
    // }

    //
    printf("%d\n",f-g);
  }
  return 0;
}