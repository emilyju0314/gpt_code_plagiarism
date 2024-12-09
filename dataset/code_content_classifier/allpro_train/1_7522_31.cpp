#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<lli,lli> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX


int dijkstra(int n,int s,vector<mp>* vs,lli* dist,int g=-1){
	memset(dist,-1,sizeof(lli)*n);
	//rep(i,n)dist[i]=-1;
	priority_queue<mp,vector<mp>,greater<mp> > que;
	que.push(mp(0,s));
	while(!que.empty()){
		mp pa=que.top();
		que.pop();
		lli co=pa.fir,
			no=pa.sec;
		if(dist[no]!=-1 && dist[no]<co)continue;
		dist[no]=co;
		if(no==g)return co;
		rep(i,vs[no].size()){
			mp pb=vs[no][i];
			lli to=pb.fir,
				tc=co+pb.sec;
			if(dist[to]!=-1 && dist[to]<=tc)continue;
			dist[to]=tc;
			que.push(mp(tc,to));
		}
	}
	return -1;
}


int n,m,N;
vector<mp> vs[100005];
lli ds[100005];
lli dt[100005];
mp dats[100005];

vector<lli> bit[400005];

void set(int p){//to 1-index
	int td = p;
	//printf("%d %d %d\n",p,dats[p].fir,dats[p].sec);
	p++;
	while(p<=N){
		bit[p].push_back(dats[td].sec);
		p += (p&(-p));
	}
}

void init(){
	N=1;
	while(N<=n+5)N*=2;
	
	rep(i,n){
		set(i);
	}
	reg(i,1,N){
		sort(bit[i].begin(),bit[i].end());
	}
}

int query(lli p,lli q){
	int st = upper_bound(ds,ds+n,p)-ds;
	//printf("que .. p .. %d is %d\n",p,st);
	//st--daga,1-indexednanodest++de.
	int res = 0;
	while(st>0){
		vector<lli>& nv = bit[st];
		int on = (lower_bound(nv.begin(),nv.end(),q)  - nv.begin()); //if(on>0)on--;
		
		//printf("on .. st .. %d q .. %d is %d\n",st,q,on);
		//rep(i,nv.size())printf("%d ",nv[i]);
		//printf("\nsiz .. %d\n",((int)nv.size()));
		res += nv.size() - on;
		st -= (st&(-st));
	}
	return res;
}

int main(void){
	/*
	int ha[5]={1,3,3,4,4};
	printf("%d %d\n",lower_bound(ha,ha+5,2)-ha,upper_bound(ha,ha+5,2)-ha);
	*/
	scanf("%d%d",&n,&m);
	rep(i,m){
		lli a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		vs[a].push_back(mp(b,c));
		vs[b].push_back(mp(a,c));
	}
	
	dijkstra(n,0,vs,ds);
	dijkstra(n,n-1,vs,dt);
	
	rep(i,n){
		dats[i] = mp(ds[i],dt[i]);
		//printf("dists .. %d %d %d\n",i,ds[i],dt[i]);
	}
	sort(dats,dats+n);
	sort(ds,ds+n);
	
	init();
	
	int iq;
	scanf("%d",&iq);
	rep(i,iq){
		lli a,b;
		scanf("%lld%lld",&a,&b);
		printf("%d\n",query(a,b));
	}
	
	return 0;
}