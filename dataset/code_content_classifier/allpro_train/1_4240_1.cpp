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
//const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
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
int N,M;
int L[100001];
int nexts[17][50001];

void calcNext(int X){
  memset(nexts,-1,sizeof(nexts));
  int tail=0;
  int sum=0;
  // if(X==4){
  //   cout<<endl;
  // }
  for(int head=0;head<N;head++){
    //sum+=L[head];
    while(tail<N){
      sum+=L[tail];
      if(sum>X){
        sum-=L[tail];
        break;
      }
      tail++;
    }
    nexts[0][head]=tail;
    sum-=L[head];
  }
  for(int i=1;i<17;i++){
    for(int j=0;j<N;j++){
      if(nexts[i-1][j]==-1)nexts[i][j]=-1;
      else nexts[i][j]=nexts[i-1][nexts[i-1][j]];
    }
  }
}

// [from,to]の範囲の数字をM-1個でoverlapできるか？
int isOverLap(int from,int to){
  int num=M-1;
  int pos=from;
  for(int i=0;num>0;i++){
    if(num%2)pos=nexts[i][pos];
    if(pos==-1)break;
    num/=2;
  }
  return (pos==-1||to<pos);
}

bool check(int X){
  if(M==1){
    int sum=0;
    for(int i=0;i<N;i++)sum+=L[i];
    return (sum<=X);
  }
  else{
    int head=0;
    int tail=0;
    int sum=L[0];
    tail=N-1;
    while(tail!=head){
      sum+=L[tail];
      if(sum>X){
        sum-=L[tail];
        break;
      }
      tail--;
    }
    if(tail==head){
      return true;
    }
    else{
      //tail++;
      // それぞれの場所から
      // 2^0,2^1,2^2,2^3,...個先へ行った場所が何になるかを計算
      // if(X==4){
      //   cout<<endl;
      // }
      calcNext(X);
      //tail++;
      while(tail<N){
        while(1){
          head++;
          if(sum+L[head]>X){
            head--;
            break;
          }
          sum+=L[head];
        }
        if(isOverLap(head+1,tail))return true;
        tail++;
        if(tail==N)break;
        sum-=L[tail];
      }
    }
  }
  return false;
}

void solve(){
  //ifstream cin("in.txt");
  cin>>N>>M;
  for(int i=0;i<N;i++)cin>>L[i];
  int lb=0;
  int ub=0;
  for(int i=0;i<N;i++){
    lb=max(lb,L[i]);
    ub+=L[i];
  }
  lb--;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(check(mid))ub=mid;
    else lb=mid;
  }
  cout<<ub<<endl;
}

int main(){

  solve();
  
  return 0;
}