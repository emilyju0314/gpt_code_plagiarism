#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define F first
#define S second
#define X real()
#define Y imag()
#define PB push_back 
#define BE(c) c.begin(),c.end()
using namespace std;
typedef long long LL;
typedef complex<int> cld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef vector<ut,pr> ppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
typedef vector<ppr> Vppr;
const int SIZE=1+1e+5;
const int INF=1<<30;
const int SEGSIZE=3*1e+8;
int num[SIZE];
Vpr leasts,mosts;
int start[SIZE],ender[SIZE];
int least[SIZE],most[SIZE];
bool isfirst[SIZE];
map<int,int> BIT;
PQ qu;
void add(int x,int p){
	while(x<=SEGSIZE){
		BIT[x]+=p;
		x+=x&-x;
	}
}
int query(int x){

	int sum=0;
	while(x>0){
		if(BIT.find(x)!=BIT.end()) sum+=BIT[x];
		x-=x&-x;
	}
	return sum;
}
int query(int a,int b){
	return query(b)-query(a-1);
}
int main(){
	int D,l,r,e,Q;
	cin >> D;
	FOR(i,1,D+1)
		cin >> num[i];
	REP(i,SIZE)
		isfirst[i]=true;
	cin >> Q;
	REP(i,Q){
		cin >> l >> r >> e;
		least[i]=min(num[l],num[r])-e-1;
		most[i]=max(num[l],num[r])+e+1;
		if(l-1>0) qu.push(pr(l-1,i));
		else isfirst[i]=false;
		qu.push(pr(r,i));
	}
	int side=1e+8+1;
	FOR(i,1,D+1){
		add(num[i]+side,1);
		while(!qu.empty() && qu.top().F==i){
			int target=qu.top().S;
			qu.pop();
			if(isfirst[target])
				start[target]=query(least[target]+side)+query(most[target]+side,SEGSIZE);
			else
				ender[target]=query(least[target]+side)+query(most[target]+side,SEGSIZE);
			isfirst[target]=false;
		}
	}
	REP(i,Q){
		printf("%d\n",ender[i]-start[i]);
	}
}