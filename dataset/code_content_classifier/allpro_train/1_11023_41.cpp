#include<iostream>
#include<cstring>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
#define mod1 998244353
#define mod2 100000007
#define mod3 20050329
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int f=1,ans=0; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=2e5+11;
int N,M,A[MAXN],cnt0,cnt1,cnt2,Ans,rnk[MAXN]; char S[MAXN];
vector<int> vec[MAXN];
struct node{
	int h1,h2,h3,id;
}tp[MAXN];
bool cmp(node x1,node x2){
	if(x1.h1!=x2.h1) return x1.h1<x2.h1;
	if(x1.h2!=x2.h2) return x1.h2<x2.h2;
	return x1.h3<x2.h3;
}
vector<int> Buc;
struct Trie{
	int ch[MAXN][27],tot,siz[MAXN],Id[MAXN]; vector<int> cyf;
	int Liml[MAXN],Limr[MAXN];
	void init(){
		memset(Liml,127/3,sizeof(Liml)),memset(Limr,-127/3,sizeof(Limr));
	}
	void clear(){
		cyf.clear(); for(int i=1;i<=tot;i++){siz[i]=0,Id[i]=0; Liml[i]=Liml[0],Limr[i]=Limr[0]; for(int j=0;j<26;j++) ch[i][j]=0;}
		tot=1; return;
	}
	void ins(int id){
		int u=1; siz[u]++; Liml[u]=min(Liml[u],id),Limr[u]=max(Limr[u],id);
		for(auto c:Buc){
			if(!ch[u][c]) ch[u][c]=++tot; u=ch[u][c]; siz[u]++;
			Liml[u]=min(Liml[u],id),Limr[u]=max(Limr[u],id);
		}
		Id[u]=id; return;
	}
	void dfs(int u){
		if(Id[u]) cyf.pb(Id[u]);
		for(int i=0;i<26;i++) if(ch[u][i]) dfs(ch[u][i]);
		return;
	}
}T1;
bool F(int x,int y){
	int psl=0,psr=M-1;
	while(vec[rnk[x]][psl]==vec[rnk[y]][psl]) psl++;
	while(vec[rnk[x]][psr]==vec[rnk[y]][psr]) psr--;
	bool ff=1;
	for(int i=psl+1;i<=psr;i++) ff&=(vec[rnk[x]][i-1]<=vec[rnk[x]][i]);
	if(ff) return 1; 
	ff=1;
	for(int i=psl+1;i<=psr;i++) ff&=(vec[rnk[y]][i-1]<=vec[rnk[y]][i]);
	if(ff) return 1;
	return 0;	
}
struct Query{int opt; vector<int> vec;};
vector<Query> Vec[MAXN];
void calc(int L,int R){
	T1.clear();
	for(int i=L;i<=R;i++){
		Buc.clear(); for(auto c:vec[rnk[i]]) Buc.pb(c);
		T1.ins(rnk[i]);
	}
	T1.dfs(1);
	for(int i=0;i<R-L+1;i++) rnk[L+i]=T1.cyf[i];
	T1.clear();
	for(int i=L;i<=R;i++){
		Buc.clear(); for(auto c:vec[rnk[i]]) Buc.pb(c);
		T1.ins(i);
	}
	for(int i=L;i<=R;i++){
		//for(auto v:vec[rnk[i]]) cerr<<v;cerr<<endl;
		int u=1;
		for(int l=0;l<M;l++){
			int psl=T1.Liml[u],psr=T1.Limr[u];
			int r=l; while(r<M-1&&vec[rnk[i]][r]<=vec[rnk[i]][r+1]) ++r;
			if(psl<=i-1){
				Query GG; GG.vec.clear();
				GG.opt=1; for(int c=M-1;c>=r+1;c--) GG.vec.pb(vec[rnk[i]][c]); Vec[i-1].pb(GG);
				GG.opt=-1; Vec[psl-1].pb(GG);
			}
			if(i+1<=psr){
				Query GG; GG.vec.clear();
				GG.opt=1; for(int c=M-1;c>=r+1;c--) GG.vec.pb(vec[rnk[i]][c]); Vec[psr].pb(GG);
				GG.opt=-1; Vec[i].pb(GG);
			}
			for(int j=l;j<=r;j++) u=T1.ch[u][vec[rnk[i]][j]];
			l=r;
		}
	}
	T1.clear();
	for(int i=L;i<=R;i++){
		//cerr<<"Ins:"<<endl;
		//for(auto c:vec[rnk[i]]) cerr<<c<<" ";cerr<<endl;
		Buc.clear(); for(int j=M-1;j>=0;j--) Buc.pb(vec[rnk[i]][j]);
		T1.ins(i);
		for(auto pp:Vec[i]){
			//cerr<<"Find:"<<endl;
			int u=1; for(auto c:pp.vec) u=T1.ch[u][c];
			cnt1+=pp.opt*T1.siz[u];
			
			//cerr<<"opt:"<<pp.opt<<"===>";
			//for(auto c:pp.vec) cerr<<c<<" ";
			//cerr<<endl;
			//cerr<<"Ans:"<<T1.siz[u]<<endl;
		}
	}
	//cerr<<"cnt1:"<<cnt1<<endl; exit(0);
	//for(int i=L;i<=R;i++) for(int j=i+1;j<=R;j++) if(F(i,j)) cnt1++;
	return;
}
signed main(){
	//freopen("4.in","r",stdin);
	N=read(); 
	for(int i=1;i<=N;i++){
		scanf("%s",S+1); M=strlen(S+1);
		for(int j=1;j<=M;j++) A[j]=S[j]-'a',vec[i].pb(A[j]);
		sort(A+1,A+M+1);
		int res1=0,res2=0,res3=0;
		for(int j=1;j<=M;j++) res1=(res1*27+A[j])%mod1,res2=(res2*27+A[j])%mod2,res3=(res3*27+A[j])%mod3;
		tp[i].h1=res1,tp[i].h2=res2,tp[i].h3=res3; tp[i].id=i;
	} sort(tp+1,tp+N+1,cmp); cnt0=N*N;
	T1.init();
	for(int i=1;i<=N;i++) rnk[i]=tp[i].id;
	for(int l=1;l<=N;l++){
		int r=l; while(tp[r+1].h1==tp[l].h1&&tp[r+1].h2==tp[l].h2&&tp[r+1].h3==tp[l].h3&&r<N) ++r;
		cnt0-=(r-l+1)*(r-l+1); calc(l,r);
		l=r;
	} cnt0/=2; cnt2=N*(N-1)/2-cnt0-cnt1;
	//cerr<<"cnt0:"<<cnt0<<" cnt1:"<<cnt1<<" cnt2:"<<cnt2<<endl;
	printf("%lld\n",cnt0*1337+cnt1+cnt2*2);
	return 0;
}