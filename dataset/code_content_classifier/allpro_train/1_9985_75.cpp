#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define ones(x) __builtin_popcount(x)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define dbg(x) cout << (#x) << " = " << x << " "
#define fini cout << "\n";
#define line cout << "-----------------------------------\n";
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
/*
int read (){
    int x = 0, f = 1; char s = getchar();while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
    while (s >= '0' && s <= '9') x = x * 10 + s - '0', s = getchar();
    return x * f; 
}*/
const int M=5e5+7;
const int N=1e4+7;
const ll inf=1e18;
const int mod=2147483647;

int n;
int arr[M];
int l[M];
int r[M];
int f[M];
int fd[M];
int dp[M];

void go(){
    cin >> n;
    fp(i,1,n+1){
        cin >> arr[i];
        if (l[arr[i]] == 0) l[arr[i]] = i;
        r[arr[i]] = i;
        f[arr[i]]++;
    }

    fn(i,n,1){
        fd[arr[i]]++;
        if (l[arr[i]] == i) dp[i] = max(dp[i+1], f[arr[i]] + dp[r[arr[i]]+1]);
        if (l[arr[i]] != i) dp[i] = max(dp[i+1], fd[arr[i]]);
    }

    cout << n - dp[1] << "\n";
}
 
int main(){ 
 
    fastio;
    int tst = 1;
    // cout << fixed << setprecision(17);
    // cin >> tst;
    fp(i,0,tst) go();
 
    return 0;
}