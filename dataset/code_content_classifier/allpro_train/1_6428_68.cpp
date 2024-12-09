//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<long long>      vll;
typedef vector<pair<int, int>> vpi;

#define pb            push_back
#define pf            push_front
#define all(x)        begin(x), end(x)
#define sz(x)         (int)(x).size()
#define ff            first
#define ss            second
#define mp            make_pair
#define lb            lower_bound
#define ub            upper_bound
#define Tcase()       int tcc; cin >> tcc; while(tcc--)
#define FOR(i, a, b)  for(int i = (a); i < (b); i++)
#define F0R(i, a)     FOR(i, 0, a)

const ll  MOD   = 1e9 + 7; // 998244353;
const ll  INF   = 9e18;
const int MX    = 2e5 + 5;
const ld  PI    = acos((ld) -1);
const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool chk(vector<int> Set, int n, int sum){

    bool subset[n + 1][sum + 1];

    for(int i = 0; i <= n; i++)
        subset[i][0] = true;

    for(int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < Set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if(j >= Set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - Set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main(){

    setIO();

    set<int> bad[10];

    FOR(i, 2, 10){
        ll p = 10 * i;
        vi S;
        FOR(j, 1, p + 1){
            ll v = j;
            while(v){
                if(v % 10 == i){
                    F0R(k, 10) S.pb(j);
                    break;
                }
                v /= 10;
            }
        }
        FOR(j, 1, p + 1){
            if(!chk(S, sz(S), j)) bad[i].insert(j);
        }
    }

    Tcase(){

        ll n, x;
        cin >> n >> x;

        ll a[n];
        F0R(i, n) cin >> a[i];

        F0R(i, n){
            if(bad[x].count(a[i])) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
