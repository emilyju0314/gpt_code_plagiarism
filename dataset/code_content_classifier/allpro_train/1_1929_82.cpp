/*------------------------------------
.......Bismillahir Rahmanir Rahim.....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream> 
#include <algorithm> 
#include <stdio.h> 
#include <cmath> 
#include <vector> 
#include <set> 
#include <utility> 
#include <list> 
#include <stack> 
#include <map> 
#include <cstring> 
#include <unordered_map> 
#include <queue> 
#include <functional> 
#define   int  long long 
#define   ld   long double 
#define   pb   push_back 
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   fast  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
#define   sz(x)  (int)x.size() 
#define   all(a) a.begin(),a.end() 
#define   print(ok) cout << ((ok) > 0 ? "YES" : "NO") << '\n' ; 
#define   ff   first 
#define   ss   second 
#define   pi   acos(-1.0) 
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std; 

const int  mod = 998244353 ; 

inline void solve() { 
    int a , b, ans = 1e9 ; 
    cin >> a >> b ; 
    int r = 100 ; 
    for (int i=0;i<=r ; ++i) {
        int cnt = 0, x = a, c = i+b ; 
        if (c==1) {
            cnt++; c++ ; 
        }
        while (x > 0) {
            x /= c ;
            ++cnt ; 
        }
        ans = min(ans, cnt+i) ; 
    }
    cout << ans << endl ; 
} 

signed main() 
{ 
    fast ; 
    int n = 1 ;  cin >> n ; 
    while (n--) solve() ; 
    return 0 ; 
} 
