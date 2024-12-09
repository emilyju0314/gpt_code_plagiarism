#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

ll k, l, r, t, x, y;
bool vist[MAXN];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    lrii(k, l); lrii(r, t); lrii(x, y);
    r -= l;
    k -= l;
    if(y > r){
        printf(k / x >= t ? "Yes\n" : "No\n");
        return 0;
    }
    if(x >= y){
        if(k + y > r) k -= x, t--; 
        if(k < 0) {printf("No\n"); return 0;}
        if(t == 0) {printf("Yes\n"); return 0;}
        printf(k / t >= x - y ? "Yes\n" : "No\n");
        return 0;
    }
    if(r - y >= x) { printf("Yes\n"); return 0; }

    while(true){
        t -= k / x;
        k %= x;
        if(t <= 0) { printf("Yes\n"); return 0; }
        if(k > r - y) { printf("No\n"); return 0; }
        if(vist[k]) { printf("Yes\n"); return 0; }
        vist[k] = true;
        k += y;
    }

    return 0;
}
