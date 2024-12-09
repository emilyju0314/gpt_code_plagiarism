#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

const int INF = 1001001001;

int input_bit()
{
    int r = 0;
    rep(i, 16){
        int b;
        cin >> b;
        r <<= 1;
        r += b;
    }
    return r;
}

int func(int n, int c)
{
    vi a(n);
    rep(i, n) a[i] = input_bit();
    
    vi b(c);
    rep(i, c) b[i] = input_bit();
    
    vvi dp(n+1);
    dp[0].assign(1<<16, -INF);
    dp[0][0] = 0;
    
    rep(i, n){
        dp[i+1].assign(1<<16, -INF);
        rep(m, 1<<16){
            if(dp[i][m] == -INF) continue;
            
            rep(j, c){
                int v = m | a[i];
                int cnt = 0;
                rep(k, 16){
                    if(((v>>k)&1) && ((b[j]>>k)&1)){
                        ++cnt;
                        v ^= 1 << k;
                    }
                }
                dp[i+1][v] = max(dp[i+1][v], dp[i][m]+ cnt);
            }
        }
        dp[i].clear();
    }
    
    return *max_element(dp[n].begin(), dp[n].end());
}


int main()
{
    int n, c;
    while(cin >> n >> c, n){
        cout << func(n, c) << endl;
    }
}