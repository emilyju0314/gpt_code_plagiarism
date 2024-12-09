#include <bits/stdc++.h>

using namespace std;


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]";}
template <typename T, typename... V>
void print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;

#define pb push_back
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define mp(x, y) make_pair((x), (y))

const int MAXN = 1002;
int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
int u[MAXN], cnt;
int l;
int r;

ull gcd (ull a, ull b) {
	return b ? gcd (b, a % b) : a;
}

ull lcm (ull a, ull b) {
	return a / gcd (a, b) * b;
}

void CAD(){
    int n;
    cin>>n;
    int a[n+5],sum[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=0;
    }
    int ma=0;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;){
            if(sum[j]!=0){
                sum[i]+=sum[j];
                break;
            }
            sum[i]+=a[j];
            j+=a[j];
        }
        //cout<<sum[i]<<" ";
        ma = max(ma,sum[i]);
    }


    cout<<ma<<endl;


}
int main(){
speed;
int t=1;
cin>>t;
while(t--)CAD();
}
