#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

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
    return ps[n];
  }

  int size(){
    return ps.size();
  }
};

int main(){
  Prime<1000000+1000> p;
  ll n;
  while(cin>>n, n){
    long long ans = 1;
    long long org = n;
    for(int i=0; p[i] <= n && (ll)p[i] * p[i] <= org; i++){
      int cc = 0;
      while(n % p[i] == 0){
	cc++;
	n /= p[i];
      }
      if(cc != 0)
	ans *= (cc + 1) + (cc + 1) - 1;
    }

    if(n != 1)
      ans *= 3;

    cout << (ans - 1) / 2 + 1 << endl;
  }
  return 0;
}