#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define enld '\n'
#define rep(i,n) for(int i=0; i<(n); i++)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,-1,1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H,W;
    cin >> H >> W;
    vector<string> G(H+2);
    for(int i=1; i<=H; i++){
         cin >> G[i];
         G[i] = "#" + G[i];
    }
    vector<vector<bool>> ok(H+2,vector<bool> (W+2,true));
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(G[i][j] == 'x'){
                ok[i][j] = false;
                for(int k=0; k<8; k++){
                    ok[i+dy[k]][j+dx[k]] = false;
                }
            }else if(G[i][j] == 'o'){
                for(int k=-1; k<=1; k++){
                    ok[i][j+k] = false;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=2; i<=H; i++){
        for(int j=1; j<=W; j++){
            cnt += ok[i][j];            
        }
    }
    cout << cnt << "\n";
    return 0;
}

