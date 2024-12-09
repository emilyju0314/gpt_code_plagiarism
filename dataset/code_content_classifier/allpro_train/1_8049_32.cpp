#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

int N,L,M;
string s;
vector<int> e;

vector<int> operator*(const vector<int>& a,const vector<int>& b){
  vector<int> res(a.size());
  rep(i,a.size())res[i]=b[a[i]];
  return res;
}

vector<int> seq(int l,int r){
  if(s[l]!='('){
    int i=l+1;
    while(i<r&&isdigit(s[i]))i++;
    if(i==r){ // opr
      int num=stoi(s.substr(l+1,r-l-1));
      num--;
      vector<int> res=e;
      if(s[l]=='L'){
        rep(i,M){
          if(i/N==num){
            int base=(i/N)*N;
            res[i]=(i-base-1+N)%N+base;
          }
        }
      }else if(s[l]=='R'){
        rep(i,M){
          if(i/N==num){
            int base=(i/N)*N;
            res[i]=(i-base+1)%N+base;
          }
        }
      }else if(s[l]=='U'){
        rep(i,M){
          if(i%N==num){
            int base=i%N;
            res[i]=((((i-base)/N)-1+N)%N)*N+base;
          }
        }
      }else{
        rep(i,M){
          if(i%N==num){
            int base=i%N;
            res[i]=((((i-base)/N)+1)%N)*N+base;
          }
        }
      }
      return res;
    }
  }

  vector<int> res=e;
  for(int i=l;i<r;){
    if(s[i]=='('){ // rept
      int j=i+1;
      int lev=1;
      while(lev!=0){
        if(s[j]=='(')lev++;
        if(s[j]==')')lev--;
        j++;
      }
      int k=j;
      while(k<r&&isdigit(s[k]))k++;
      vector<vector<int> > nxt(vector<vector<int> >(30,vector<int>(M)));
      nxt[0]=seq(i+1,j-1);
      repl(b,1,30)nxt[b]=nxt[b-1]*nxt[b-1];
      int t=stoi(s.substr(j,k-j));
      rep(b,30){
        if((t>>b)&1)res=res*nxt[b];
      }
      i=k;
    }else{ // seq
      int j=i+1;
      while(j<r&&isdigit(s[j]))j++;
      res=res*seq(i,j);
      i=j;
    }
  }
  return res;
}

int main(){
  cin>>N>>L;
  M=N*N;
  cin>>s;
  rep(i,M)e.push_back(i);
  vector<int> res=seq(0,L);
  vector<int> ans;
  rep(i,M)ans.push_back(i);
  rep(i,M)ans[res[i]]=i;
  rep(i,N){
    rep(j,N){
      printf("%d%c", ans[i*N+j]+1,j==N-1?'\n':' ');
    }
  }
  return 0;
}

