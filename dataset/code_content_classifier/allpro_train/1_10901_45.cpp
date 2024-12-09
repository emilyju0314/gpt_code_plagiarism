#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef long long ll;
/*
  (px + q)(rx + s)
  p > 0
  r > 0
  (p > r) or (p = r and q >= s)

  prx^2 + (ps + qr)x + qs
  a = pr
  b = ps + qr
  c = qs
 */
int main(){
    ll a,b,c,p,q,r,s,i,j,k;

    while( cin >> a >> b >> c, a|b|c ){
        bool ok = false;

        for(i=1; i*i<=a; i++){
            if( a%i != 0 ) continue;
            p = a/i, r = i;

            for(j=-abs(c); j<=abs(c); j++){
                if( (j == 0 && c != 0) || (j != 0 && abs(c)%abs(j) != 0) ) continue;
                if( j != 0 ){
                    q = c/j, s = j;
                }
                else{
                    q = b/r, s = 0;
                    if( p*s + q*r != b ) q = 0, s = b/p;
                    if( p*s + q*r != b ) continue;
                }

                //printf("%lld %lld %lld %lld\n",p,q,r,s);
                if( !( p*r == a && q*s == c && (p*s + q*r == b || p*r + q*s == b) ) ) continue;

                ok = true;
                if( p == r ){
                    printf("%lld %lld %lld %lld\n", p,max(q,s),r,min(q,s));
                }
                else{
                    if( p*s + q*r == b ){
                        printf("%lld %lld %lld %lld\n", p,q,r,s);
                    }
                    else{
                        printf("%lld %lld %lld %lld\n", p,s,r,q);
                    }
                }
                break;
            }
            if( ok ) break;
        }
        if( !ok ) puts("Impossible");
    }
    return 0;
}