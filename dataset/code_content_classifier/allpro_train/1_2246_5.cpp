#include <cstdio>

using namespace std;

typedef long long ll;

ll mod_pow(ll a,ll b,ll m)
{
  if( b == 0 ) return 1;
  ll res = mod_pow(a*a%m,b/2,m);
  if(b&1)res=(a*res)%m;
  return res;
}

int main(void)
{
  ll n,m,k;
  scanf("%lld%lld%lld",&n,&m,&k);
  int a = n%10,b = 1;
  int shu[11] = {};
  int sss[11] = {},sz = 0;
  //for( int i = 0; i < m; i++ ) b = (b*a)%10;
  b = mod_pow(a,m,10);
  for( int i = 0; i < 10; i++ ) {
    if( shu[a] ) break;
    shu[a] = 1;
    sss[sz+1] = sss[sz]+a;
    ++sz;
    a = (a*b)%10;
  }
  //printf("%d\n",sz);
  ll res = 0;
  res += k/sz*sss[sz];
  k %= sz;
  for( int i = 0; i < k; i++ ) {
    res += a;
    a *= b;
    a %= 10;
    //printf("%d\n",a);
  }
  printf("%lld\n",res);
  return 0;
}
