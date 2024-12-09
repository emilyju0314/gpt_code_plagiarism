#include <bits/stdc++.h>
#define show(x) cout<<#x<<" "<<x<<endl
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define all(c) c.begin(),c.end()
using namespace std;
typedef pair<double,double> P;
typedef pair<int,int> Pi;
typedef pair<double,Pi> dP;
int x[100],y[100];
double dis(P p,P q){
	return sqrt((p.fs-q.fs)*(p.fs-q.fs)+(p.sc-q.sc)*(p.sc-q.sc));
}
int main(){
	while(true){
		int N;
		cin>>N;
		if(N==0) break;
		rep(i,N) cin>>x[i]>>y[i];
		vector<int> ys;
		rep(i,N) ys.pb(y[i]);
		sort(all(ys));
		ys.erase(unique(all(ys)),ys.end());
		vector<P> ps;
		rep(i,N-1){
			for(int yy:ys){
				if(y[i]<yy&&yy<y[i+1]){
					double xx=x[i]+(double)(x[i+1]-x[i])*(yy-y[i])/(y[i+1]-y[i]);
					ps.pb(P(xx,yy));
				}
				if(y[i]>yy&&yy>y[i+1]){
					double xx=x[i]+(double)(x[i+1]-x[i])*(y[i]-yy)/(y[i]-y[i+1]);
					ps.pb(P(xx,yy));
				}
			}
		}
		rep(i,N) ps.pb(P(x[i],y[i]));
		sort(all(ps));
		int M=ps.size();
//		show(M);
//		rep(i,M) cout<<"    "<<ps[i].fs<<" "<<ps[i].sc<<endl;
		priority_queue<dP,vector<dP>,greater<dP> > que;
		map<Pi,double> mp;
		que.push(dP(0,Pi(0,M-1)));
		mp[Pi(0,M-1)]=0;
		while(!que.empty()){
			dP dp=que.top();
			que.pop();
			double d=dp.fs;
			Pi p=dp.sc;
			if(mp.count(p)&&mp[p]<d) continue;
			int x=p.fs,y=p.sc;
			for(int di=-1;di<=1;di++) for(int dj=-1;dj<=1;dj++){
				int nx=x+di,ny=y+dj;
				if(!(0<=nx&&nx<M&&0<=ny&&ny<M)) continue;
				if(ps[nx].sc!=ps[ny].sc) continue;
				double dist=dis(ps[x],ps[nx])+dis(ps[y],ps[ny]);
				Pi np=Pi(nx,ny);
				if(!mp.count(np)||mp[np]>d+dist){
					mp[np]=d+dist;
					que.push(dP(d+dist,np));
				}
			}
		}
		double ans=1e9;
		rep(i,M) ans=min(ans,mp[Pi(i,i)]);
		printf("%.12f\n",ans);
	}
}