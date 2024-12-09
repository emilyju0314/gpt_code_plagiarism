#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int n;
vector<mp> vs[10005];
int kar[10005];

int dfsb(int no,int p){
	kar[no]=0;
	rep(i,vs[no].size()){
		int to=vs[no][i].fir,
			co=vs[no][i].sec;
		if(to==p)continue;
		int tc=dfsb(to,no)+co;
		kar[no]=max(kar[no],tc);
	}
	return kar[no];
}

int dp[10005];

void dfs(int no,int p){
	vector<int> nds(1,dp[no]);
	rep(i,vs[no].size()){
		int to=vs[no][i].fir,
			co=vs[no][i].sec;
		if(to==p)continue;
		nds.push_back(kar[to]+co);
	}
	sort(nds.begin(),nds.end(),greater<int>());
	dp[no]=nds[0];
	rep(i,vs[no].size()){
		int to=vs[no][i].fir,
			co=vs[no][i].sec;
		if(to==p)continue;
		int upc=nds[0];
		if(kar[to]+co==upc)upc=nds[1];
		upc+=co;
		dp[to]=max(dp[to],upc);
		
		dfs(to,no);
	}
}

int main(void){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		vs[a].push_back(mp(b,c));
		vs[b].push_back(mp(a,c));
	}
	dfsb(0,-1);
	//rep(i,n)printf("%d\n",kar[i]);
	dfs(0,-1);
	
	rep(i,n)printf("%d\n",dp[i]);

	return 0;
}