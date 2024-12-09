#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<bitset>
#include<sstream>
#include<ctime>
//#include<chrono>
//#include<random>
//#include<unordered_map>
using namespace std;

#define ll long long
#define ls o<<1
#define rs o<<1|1
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
const double pi=acos(-1.0);
const double eps=1e-6;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int t,n,m;
int a[maxn],b[maxn],c[maxn],ans[maxn];
vector<int>dif[maxn],same[maxn],up;
int main(void){
	// freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)dif[i].clear(),same[i].clear();
		up.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			if(a[i]!=b[i]){
				dif[b[i]].pb(i);
			}
			else{
				same[b[i]].pb(i);
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&c[i]);
		}
		int flag=1;
		for(int i=m;i>=1;i--){
			if(sz(dif[c[i]])){
				ans[i]=dif[c[i]].back();
				dif[c[i]].pop_back();
				up.pb(ans[i]);
				a[ans[i]]=c[i];
			}
			else if(sz(up)){
				ans[i]=up.back();
			}
			else if(sz(same[c[i]])){
				ans[i]=same[c[i]].back();
				up.pb(ans[i]);
			}
			else{
				flag=0;
				break;
			}
		}
		if(!flag){
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				flag=0;
				break;
			}
		}
		if(!flag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}