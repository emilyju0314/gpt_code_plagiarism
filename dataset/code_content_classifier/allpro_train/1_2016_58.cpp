#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=a;i>=n;i--)
#define ll long long
inline ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0) putchar('-'),x=-x;if(x>9) write(x/10);putchar(x%10+'0');}

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define ull unsigned long long
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
#define all(a) a+1,a+n+1
#define ALL(a) a.begin(),a.end()
// #define debug(a) cout <<#a << "=" << a << endl;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll<<60;
const int mod=1e9+7;
#define TT int T;cin>>T;while(T--)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);


int main(){
	TT{
		ll n,m,x;
		cin>>n>>m>>x;
		int t=(x+n-1)/n,r=x%n;
		if(r==0) r=n;
		//debug(t,r)

		// debug((r-1)*m+t)
		cout<<(r-1)*m+t<<endl;
	}
    return 0;
}
