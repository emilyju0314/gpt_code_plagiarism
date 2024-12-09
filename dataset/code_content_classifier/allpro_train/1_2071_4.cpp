#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k,n,q;
  cin>>n;
  vector<string> str(n);
  rep(i,n)cin>>str[i];
  vector<pair<string,int>> srt;
  rep(i,n)srt.emplace_back(str[i],i);
  sort(all(srt));
  vector<int> s(n),rnk(n);
  rep(i,n)
    s[i]=srt[i].Y;
  rep(i,n)
    rnk[s[i]]=i;
  set<int> st;
  cin>>q;
  int t,id;
  rep(i,q){
    cin>>t>>id;
    --id;
    if(t==1){
      st.insert(rnk[id]);
    }else if(t==2){
      st.erase(rnk[id]);
    }else{
      auto re=st.lower_bound(rnk[id]);
      if(re==st.end()){
	cout<<-1<<endl;
      }else{
	//cout<<str[id]<<","<<str[s[*re]]<<endl;
	if(str[id].size()<=str[s[*re]].size() && str[id]==str[s[*re]].substr(0,str[id].size()))
	  cout<<s[*re]+1<<endl;
	else
	  cout<<-1<<endl;
      }
    }
  }
  return 0;
}
