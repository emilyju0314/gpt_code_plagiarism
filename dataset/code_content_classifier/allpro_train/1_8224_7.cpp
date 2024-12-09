#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 100005
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
int n,m,k,d,s,ss,pos;
int a[M],b[M],c[M],cur[M];//rezi
set<P> S;

int main()
{
	LL buf;
	int id;
	scanf("%lld", &buf);
	n = buf = min(buf, (LL)M);
	RI(m,k,d,s);
	REP(i,1,m) RI(a[i], b[i], c[i]);

	if(n>m)
	{
		printf("%d\n", d*k);
		return 0;
	}
	
	ss = s;
	REP(i,1,n) S.insert( MP(0,i) );
	pos = 1;
	REP(i,1,k)
	{
		s += d;
		while(pos<=m && a[pos]<=s)
		{
			id = c[pos];
			S.erase( MP(cur[id], id) );

			cur[id] = max(cur[id], a[pos]);
			cur[id] += b[pos];
			S.insert( MP(cur[id], id) );
			pos++;
		}

		s = max(s, (*S.begin()).F);
	}
	printf("%d\n",s-ss);
	return 0;
}