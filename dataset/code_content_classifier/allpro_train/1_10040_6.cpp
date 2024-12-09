#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

struct Data {
  int start,end,onAir,recorded;
  bool operator < ( const Data &data ) const {
    if( end != data.end ) return end < data.end;
    if( start != data.start ) return start < data.start;
    return ( onAir != data.onAir ) ? onAir < data.onAir : recorded < data.recorded;
  }
};

const int MAX_N = 1100;
int N,dp[2000][2000],h,m;
vector<int> buf;

int toTime(string s){
  rep(i,(int)s.size()) if( s[i] == ':' ) s[i] = ' ';
  stringstream ss(s);
  ss >> h >> m;
  return h * 60 + m;
}

int main(){
  while( cin >> N, N ){
    vector<Data> vec(N);
    rep(i,N) {
      string a,b,c;
      cin >> a >> b >> c >> vec[i].onAir >> vec[i].recorded;
      vec[i].start = toTime(b), vec[i].end = toTime(c);
    }
    vec.push_back((Data){0,0,0,0});
    rep(i,N+2) rep(j,N+2) dp[i][j] = 0; 
    sort(vec.begin(),vec.end());
    buf.clear();
    rep(i,vec.size()) buf.push_back(vec[i].end);
    rep(i,vec.size()){
      rep(j,vec.size()){
        if( i == j ) dp[i][j] = max((i?dp[i-1][j]:0),(j?dp[i][j-1]:0));
        else if( i < j ) {
          int prev = upper_bound(buf.begin(),buf.begin()+j,vec[j].start) - buf.begin() - 1;
          dp[i][j] = max(dp[i][j-1],((prev!=-1)?dp[i][prev]:0)+vec[j].recorded);
        } else {
          int prev = upper_bound(buf.begin(),buf.begin()+i,vec[i].start) - buf.begin() - 1;
          dp[i][j] = max(dp[i-1][j],((prev!=-1)?dp[prev][j]:0)+vec[i].onAir);
        }
      }
    }
    printf("%d\n",dp[(int)vec.size()-1][(int)vec.size()-1]);
  }
  return 0;
}