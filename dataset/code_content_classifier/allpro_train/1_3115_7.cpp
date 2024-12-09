#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60)+1e9; // ~ 1.15 * 1e18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T1, class T2> ostream& operator<<(ostream& o,pair<T1,T2> p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){
  return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}
//INSERT ABOVE HERE



signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  vector<string> t[4];
  for(int i=0;i<4;i++){
    int h, w;
    cin>>h>>w;
    t[i].resize(h);
    cin>>t[i];
  }

  int n;
  cin>>n;
  for(int num_case=0;num_case<n;num_case++){
    const int H = 4, W = 10;
    vector<string> mp(H);
    cin>>mp;

    {
      int cnt = 0;
      for(int i=0;i<H;i++)
        for(int j=0;j<W;j++) cnt += mp[i][j] == '.';
      if(cnt != 12) {cout<<"No"<<endl;continue;}
    }



    auto check =[&](int y, int x, vector<string> &s){
      int h = s.size(), w = s[0].size();
      if(y + h > H || x + w > W) return 0;
      for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
          if(s[i][j] == '#' && mp[y + i][x + j] == '#') return 0;
        }
      return 1;
    };

    auto ume = [&](int y, int x, vector<string> &s, int erase){
      int h = s.size(), w = s[0].size();
      for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
          if(s[i][j] == '#') mp[y + i][x + j] = erase? '.':'#';
    };

    function<int(int, int)> dfs = [&](int idx, int ng){

      if(idx == 4){
        for(int i=0;i<H;i++)
          for(int j=0;j<W;j++) if(mp[i][j] != '#') return 0;
        return 1;
      }

      if(idx == ng) return dfs(idx + 1, ng);
      for(int i=0;i<H;i++)
        for(int j=0;j<W;j++){
          if(!check(i, j, t[idx])) continue;
          ume(i, j, t[idx], 0);
          if(dfs(idx + 1, ng)) return 1;
          ume(i, j, t[idx], 1);
        }
      return 0;
    };

    int ans = 0;
    for(int i=0;i<4 && ans == 0;i++) ans |= dfs(0, i);
    cout<<(ans? "Yes":"No")<<endl;
  }

  return 0;
}

