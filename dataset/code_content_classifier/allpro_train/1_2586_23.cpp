#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<string,string> Pss;
const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int f[MAX_N]={};
int b[MAX_N]={};
bool dp[MAX_N]={};
vector<Pss> Vs,Vs2;

int main() {
	int a,b,c,d,e,f,g,h,i;
	int total=0;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	rep(j,1000000){
		int j1=j;
		int f1=j1%10;
		j1/=10;
		int e1=j1%10;
		j1/=10;
		int d1=j1%10;
		j1/=10;
		int c1=j1%10;
		j1/=10;
		int b1=j1%10;
		int a1=j1/10;
		int r=a1+c1+b1*10+d1*100+e1*10+f1;
		int g1=r/100;
		int i1=r%10;
		int h1=(r/10)%10;
		if(a!=a1&&a>0)continue;
		if(b!=b1&&b>0)continue;
		if(c!=c1&&c>0)continue;
		if(d!=d1&&d>0)continue;
		if(e!=e1&&e>0)continue;
		if(f!=f1&&f>0)continue;
		if(g!=g1&&g>0)continue;
		if(h!=h1&&h>0)continue;
		if(i!=i1&&i>0)continue;

		int s[9]={a1,b1,c1,d1,e1,f1,g1,h1,i1};
		sort(s,s+9);
		bool flg=true;
		rep(k,9){
			if(s[k]!=k+1)flg=false;
		}
		if(flg)total++;
	}
	cout<<total<<endl;
	return 0;
}

