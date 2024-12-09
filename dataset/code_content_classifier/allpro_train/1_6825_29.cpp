#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#ifdef __GNUC__
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T n){int cnt=0;while(n){if(n%2)cnt++;n/=2;}return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}


int R,N;
int xs[101];
int ys[101];
int rs[101];
int vs[101];
double times[101];
double dists[101];
bool used[101];

typedef complex<double> P;
// 内積
double dot(const P &a, const P &b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// 外積
double cross(const P &a, const P &b) {
  return (a.real() * b.imag() - a.imag() * b.real());}
// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(const P &a, const P &b, const P &c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

int main(){

  while(cin>>R>>N&&(R|N)){
    for(int i=0;i<N;i++)cin>>xs[i]>>ys[i]>>rs[i]>>vs[i];
    // 各UFOがO(0,0)に到達する時間(m)
    for(int i=0;i<N;i++)times[i]=sqrt(xs[i]*xs[i]+ys[i]*ys[i])/vs[i];
    for(int i=0;i<N;i++)dists[i]=sqrt(xs[i]*xs[i]+ys[i]*ys[i]);
    memset(used,0,sizeof(used));
    int cnt=0;// 撃墜またはR以内の場所へUFOが移動したらインクリメント
    int res=0;
    // 1分ごとにレーザを発射し続ける
    // すべてのUFOが撃墜されるか原点よりR以内の場所へ到達した時に終了
    for(int t=1;cnt<N;t++){
      // 最初にR以下の距離になったものを消す
      for(int i=0;i<N;i++){
        if(used[i])continue;
        else if(EQ(dists[i]-vs[i]*t,R)||dists[i]-vs[i]*t<R)
          used[i]=true,cnt++,res++;
      }
      if(cnt>=N)break;
      int idx=-1;
      // 生きてるUFOのうち、一番中心間距離が近いものを見つける
      for(int i=0;i<N;i++){
        if(used[i])continue;
        if(idx==-1||dists[i]-vs[i]*t<dists[idx]-vs[idx]*t)idx=i;
      }
      // idxのUFOに対してレーザを発射
      // そのレーザで他に撃墜できるUFOを探索
      used[idx]=true,cnt++;
      double ex=xs[idx]/dists[idx];
      double ey=ys[idx]/dists[idx];
      double vx=ex*2000;
      double vy=ey*2000;
      double sx=-xs[idx]/times[idx];
      double sy=-ys[idx]/times[idx];
      for(int i=0;i<N;i++){
        if(used[i])continue;
        double eex=-xs[i]/times[i];
        double eey=-ys[i]/times[i];
        // レーザの線分と、中心の距離を比較
        double dist=distance_ls_p(P(ex*R,ey*R)
                                  ,P(vx,vy),P(xs[i]+t*eex,ys[i]+t*eey));
        // 中心との距離が円の半径以下なら破壊する
        if(EQ(dist,rs[i])||dist<rs[i])used[i]=true,cnt++;
      }
    }
    cout<<res<<endl;
  }
  return 0;
}