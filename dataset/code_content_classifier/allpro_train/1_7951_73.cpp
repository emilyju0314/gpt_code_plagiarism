#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int num[505050];
int S[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int cur=0;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		cur+=x;
		cur%=86400;
		num[cur]++;
		cur+=y;
		cur%=86400;
	}
	FOR(i,86400*3) {
		S[i+1]=S[i]+num[i];
		num[i+86400]=num[i];
	}
	int ma=0;
	FOR(i,86400*2) ma=max(ma,S[i+3600*3+1]-S[i]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
