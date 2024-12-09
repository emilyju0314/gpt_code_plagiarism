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


/*
 * 0©çm-1ÜÅÌfÉÖ·éCu
 * templateÅTCYðwè·éÌÅá±¢?
 * Prime<1000> p; Å999ÜÅÌfÌe[uªÅ«é
 * p[k] : kÔÚÌfÍ½©
 * p.isPrime(k) : kªf©Ç¤©
 */
template<int m>
class Prime{
  std::vector<bool> p;
  std::vector<int> ps;
public:
  Prime(){
    p = std::vector<bool>(m,true);
    assert(m>1);
    p[0]=p[1]=false;
    for(int i=4;i<m;i+=2)
      p[i]=false;
    ps.push_back(2);
    for(int i=3;i<m;i+=2){
      if(p[i]){
        ps.push_back(i);
        for(int j=i+i;j<m;j+=i)
          p[j]=false;
      }
    }
  }

  bool isPrime(int n){
    assert(m>n);
    return p[n];
  }

  int operator [] (int n){
    if(n<ps.size()) return ps[n];
    else return 0;
  }

  int size(){
    return ps.size();
  }
};

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

int main(){
  Prime<30200> p;
  int n;
  while(n = getInt()){
    int ans = 0;
    for(int i = 0; p[i]+p[i]+p[i] <= n; i++){
      for(int j = i; p[i]+p[j]+p[j] <= n; j++){
        int a = p[i];
        int b = p[j];
        int c = n - p[i] - p[j];
        if(c >= a + b) continue;
        if(c <= b - a) continue;
        if(!p.isPrime(c)) continue;
        ans++;
      }
    }
    print(ans);
  }
  return 0;
}