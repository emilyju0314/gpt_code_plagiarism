#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int main(){
	int n,m;
	while(cin>>m>>n,n+m){
		vector<string>in(n);
		rep(i,n)cin>>in[i];
		int q[256]={0};
		int sx,sy;
		int co=1;
		rep(i,n)rep(j,m){
			char c=in[i][j];
			c=tolower(c);
			if(c=='@')sx=i,sy=j;
			if(islower(c)&&q[c]==0){
				q[c]=co;
				q[toupper(c)]=co;
				co++;
			}
		}
		
		queue<pair<pii,pii> >w;
		w.push(pair<pii,pii>(pii(sx,sy),pii(0,0)));
		int dx[]={0,0,1,-1};
		int dy[]={1,-1,0,0};
		co=0;
		map<int,map<int,map<int,bool> > >M;
		while(!w.empty()){
			co++;
			pair<pii,pii>e=w.front();
			w.pop();
			pii a=e.first,b=e.second;
			if(M[a.first][a.second][b.second])continue;
			M[a.first][a.second][b.second]=true;
			rep(i,4){
				int nx=a.first+dx[i];
				int ny=a.second+dy[i];
				int t=b.second;
				if(in[nx][ny]=='#')continue;
//				if(isalpha(in[nx][ny])&&q[tolower(in[nx][ny])]==0)continue;
				if(in[nx][ny]=='<'){
					cout<<b.first+1<<endl;
					goto end;
				}
				if(isupper(in[nx][ny])&&!(t&1<<(q[in[nx][ny]]-1)))continue;
				if(islower(in[nx][ny]))t^=1<<(q[in[nx][ny]]-1);
				w.push(pair<pii,pii>(pii(nx,ny),pii(b.first+1,t)));
			}		
		}
		cout<<-1<<endl;
		end:;
	}
}