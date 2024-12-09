#include<iostream>
#include<functional>
#include<queue>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define pb push_back
#define all(c) c.begin(),c.end()
#define uni(c) c.erase(unique(all(c)),c.end())
using namespace std;
typedef pair<int,int > P;
int main(){
	int n;
	vector<vector<int> > c(8,vector<int>(8));
	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		priority_queue<P,vector<P>,greater<P> > que;
		int v=0;
		for(int i=0;i<n;i++){
			v=v*10+i;
		}
		int ans=0;
		map<int,bool> u;
		que.push(P(0,v));
		int m=1;
		for(int i=0;i<n;i++){
			m*=10;
		}
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int now=p.second,np=p.first;;
			if(u[now]){
				continue;
			}
			u[now]=1;
			ans=max(ans,np);
			for(int i=1;i<m;i*=10)
			for(int j=i*10;j<m;j*=10){
				int a=(now/i)%10,b=(now/j)%10;
				int nn=now-a*i-b*j+a*j+b*i;
				if(u[nn]){
					continue;
				}
				que.push(P(np+c[a][b],nn));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}