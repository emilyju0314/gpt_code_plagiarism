#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

int p[10];

bool valid(){
  int m = p[9];
  int ok;
  int sum;
  sum = p[0] + p[4] + p[8];
  if(sum % m == (p[2] + p[4] + p[6]) % m){
    ok = sum % m;
  }else{
    return false;
  }

  int sumT[3] = {0};
  int sumY[3] = {0};
  REP(i,3){
    REP(j,3){
      sumY[i] += p[3*i + j];
      sumT[i] += p[3*j + i];
    }
  }
  REP(i,3){
    if(sumT[i] % m != ok) return false;
    if(sumY[i] % m != ok) return false;
  }

  return true;
}

int solve(int now, int f){
  if(now == 10){
    //REP(i,10) printf("%d ",p[i]); puts("");
    return valid() ? 1 : 0;
  }
  if(p[now] == 0){
    int ret = 0;
    REP(i,10) if(f & (1<<i)){
      p[now] = i+1;
      ret += solve(now+1, f^(1<<i));
      p[now] = 0;
    }
    return ret;
  }else{
    int tmp = p[now]-1;
    if(!(f & (1 << tmp))) return 0;
    return solve(now+1, f^(1<<tmp));
  }
}

int main(){
  while(true){
    REP(i,10) scanf("%d",p+i);
    if(p[0] == -1) break;
    print(solve(0, (1<<10)-1));
  }
  return 0;
}