#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const ll inf=1e18;
const int N=1005,M=500005,NN=35;
int k[NN],s[NN][NN],p[NN][NN],id[NN][NN];
int nedge=1,son[N],nextt[M],ed[M];
int di[M],QQ;
bool vis[N];
int last[N],que[N],laedge[N];
ll cost[M],dist[N],sum[M],qq[M],c[NN][NN];
bool spfa(int s,int t,int n){
    for (int i=1;i<=n;i++) {dist[i]=inf;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
    int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
    while (tot) {
        int k=que[l];
        vis[k]=false;
        if (++l==n) l=0;
        tot--; 
        for(int i=son[k];i;i=nextt[i]){
            if(di[i]>0&&dist[ed[i]]>dist[k]+cost[i]){
                dist[ed[i]]=dist[k]+cost[i]; laedge[ed[i]]=i; last[ed[i]]=k;
                if(vis[ed[i]]==0) {
                    if(++r==n)r=0;
                    que[r]=ed[i]; tot++; vis[ed[i]]=true;
                }
            }
        }
    }
    return last[t]>0;
}
void costflow(int s,int t,int n){
    while(spfa(s,t,n)){
        int mmin=1e9; 
        for(int i=t;last[i];i=last[i])
		{mmin=min(mmin,di[laedge[i]]);}
        //cout<<dist[t]<<" "<<mmin<<" "<<QQ<<" "<<last[12]<<" fjzqq\n";
		if(mmin>100000000){
			qq[++QQ]=dist[t]; break;
		}
		For(i,1,mmin)qq[++QQ]=dist[t];
        for(int i=t;last[i];i=last[i]){
            di[laedge[i]]-=mmin;
            di[laedge[i]^1]+=mmin;
        }
    }
}
inline void aedge(int a,int b,int c,ll d){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void ins(int a,int b,int c,ll d){
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    aedge(a,b,c,d); aedge(b,a,0,-d);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read();
	int sss=1,ttt=2; int nodecnt=2;
	For(i,1,n){
		k[i]=read();
		id[i][0]=++nodecnt;
		For(j,1,k[i]){
			cin>>s[i][j]>>p[i][j]>>c[i][j];
			id[i][j]=++nodecnt;
		}
		ins(sss,id[i][0],1e9,0); ins(id[i][k[i]],ttt,1e9,0);
		For(j,1,k[i]){
			For(o,j+1,k[i])if(s[i][j]>s[i][o]){
				swap(s[i][j],s[i][o]); swap(p[i][j],p[i][o]); swap(c[i][j],c[i][o]);
			}
		}
	}
	For(i,1,n){
		For(j,1,k[i]){
			ins(id[i][j-1],id[i][j],p[i][j],0);
			ins(id[i][j-1],id[i][j],1e9,c[i][j]);
		}
	}
	int m=read();
	while(m--){
		int u=read(),v=read(),w=read(),j=0;
		For(i,0,k[u]){
			while(j<k[v]&&s[v][j+1]<=s[u][i]+w)j++;
			//cout<<v<<" "<<j<<" "<<u<<" dsa "<<i<<" "<<k[v]<<" "<<s[v][j+1]<<endl;
			//if(j==k[v])break;
			ins(id[v][j],id[u][i],1e9,0);
		}
	}
	costflow(sss,ttt,nodecnt);
	For(i,1,QQ)sum[i]=sum[i-1]+qq[i];
	int q=read();
	while(q--){
		ll AA=read();
		int p=lower_bound(qq+1,qq+QQ+1,AA)-qq;
		if(p>QQ)puts("-1");
		else writeln(AA*(p-1)-sum[p-1]);
	}
}
