#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef bitset<60> Bitset;
const ll INFL = 1LL << 60;
const int INF = 1000000005;
const int MOD = 1000000007;
int ddx[8] = {1,0,-1,0,1,-1,-1,1};
int ddy[8] = {0,1,0,-1,1,1,-1,-1};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct Graph{int to; ll cost;};
struct Edge{int from,to; ll cost;};
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return (a * b) / GCD(a, b); }
bool range(int x,int y,int X,int Y){if(0<=x&&x<X&&0<=y&&y<Y){return true;} return false;}
//------------------------------------------------------------------------------------------------------------------------------
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;
    vi a(3010);
    vi v;
    while(t--){
        int n;cin>>n;
        int sum = 0;
        v.clear();
        for(int i = 0; i < n; i++){
            cin>>a[i];
            sum += a[i];
            v.push_back(sum);
        }
        int ans = INF;
        for(auto num : v){
            int j = 0,s = 0,cnt = 0;
            bool ok = 1;
            for(int i = 0; i < n;) {
                while(j < n && s < num){
                    s += a[j];
                    j++;
                }
                if(s != num){
                    ok = 0; break;
                }
                cnt += j - i - 1;
                s = 0;
                i = j;
            }
            if(ok) ans = min(ans,cnt);
        }
        cout<<ans<<endl;
    }
}