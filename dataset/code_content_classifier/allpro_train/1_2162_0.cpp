#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int X[60][30];
int Y[60][30];
int g2[60][30][30];
int A[60];
int B[60];
int C[60];
double ijk[60][30];
int v[60][30];
int conv[30];
map<pair<int,int>,int> m[60];
double EPS=1e-9;
vector<pair<pair<int,int>,double> >g[60][30];
double dist(int a,int b,int c,int d){
	return sqrt((X[a][b]-X[c][d])*(X[a][b]-X[c][d])+(Y[a][b]-Y[c][d])*(Y[a][b]-Y[c][d]));
}
double ABS(double a){return max(a,-a);}
int UF[60];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<60;i++)for(int j=0;j<30;j++){
			g[i][j].clear();
			for(int k=0;k<30;k++)g2[i][j][k]=0;
		}
		for(int i=0;i<a;i++)UF[i]=-1;
		for(int i=0;i<a;i++){
			m[i].clear();
			int b;scanf("%d",&b);
			A[i]=b;
			for(int j=0;j<b;j++){
				scanf("%d%d",&X[i][j],&Y[i][j]);
				m[i][make_pair(X[i][j],Y[i][j])]=j;
			}
			int c;scanf("%d",&c);
			B[i]=c;
			for(int j=0;j<c;j++){
				int p,q;
				scanf("%d%d",&p,&q);p--;q--;
				g[i][p].push_back(make_pair(make_pair(i,q),dist(i,p,i,q)));
				g[i][q].push_back(make_pair(make_pair(i,p),dist(i,p,i,q)));
				g2[i][p][q]=g2[i][q][p]=1;
			}
			int d;scanf("%d",&d);
			C[i]=d;
			for(int j=0;j<d;j++){
				int p,q,r;
				scanf("%d%d%d",&p,&q,&r);p--;q--;r--;
				g[i][p].push_back(make_pair(make_pair(q,r),0));
			}
		}
		for(int i=0;i<a;i++){
			for(int j=i+1;j<a;j++){
				if(A[i]!=A[j]||B[i]!=B[j])continue;
				if(FIND(i)==FIND(j))continue;
				for(int k=0;k<A[j];k++){
					if(FIND(i)==FIND(j))break;
					for(int l=0;l<A[j];l++){
						if(ABS(dist(i,0,i,1)-dist(j,k,j,l))>EPS)continue;
						double th=atan2(Y[i][1]-Y[i][0],X[i][1]-X[i][0])-atan2(Y[j][l]-Y[j][k],X[j][l]-X[j][k]);
						bool ok=true;
						for(int x=0;x<A[j];x++){
							double vx=X[j][x]-X[j][k];
							double vy=Y[j][x]-Y[j][k];
							double tx=cos(th)*vx-sin(th)*vy;
							double ty=sin(th)*vx+cos(th)*vy;
							int sx=(int)(X[i][0]+tx+0.5);int sy=(int)(Y[i][0]+ty+0.5);
							if(X[i][0]+tx+0.5<0)sx--;
							if(Y[i][0]+ty+0.5<0)sy--;
							
							if(ABS(X[i][0]+tx-sx)>EPS||ABS(Y[i][0]+ty-sy)>EPS){ok=false;break;}
							if(m[i].count(make_pair(sx,sy))==0){ok=false;break;}
							conv[m[i][make_pair(sx,sy)]]=x;
						}
						if(!ok)continue;
						for(int x=0;x<A[i];x++){
							for(int y=0;y<g[i][x].size();y++){
								if(g[i][x][y].second<EPS)continue;
								if(!g2[j][conv[x]][conv[g[i][x][y].first.second]]){ok=false;break;}
							}
						}
						if(ok){
							UNION(i,j);
							for(int x=0;x<A[i];x++){
								g[i][x].push_back(make_pair(make_pair(j,conv[x]),0));
								g[j][conv[x]].push_back(make_pair(make_pair(i,x),0));
							}
							break;
						}
					}
				}
			}
		}
		priority_queue<pair<double,pair<int,int> > >Q;
		int s1,s2,d1,d2;
		scanf("%d%d%d%d",&s1,&s2,&d1,&d2);
		s1--;s2--;d1--;d2--;
		Q.push(make_pair(0,make_pair(s1,s2)));
		for(int i=0;i<60;i++)for(int j=0;j<30;j++){
			ijk[i][j]=999999999;
			v[i][j]=0;
		}
		ijk[s1][s2]=0;
		while(Q.size()){
			double cost=-Q.top().first;
			int at1=Q.top().second.first;
			int at2=Q.top().second.second;
		//	printf("%d %d %f\n",at1,at2,cost);
			Q.pop();
			if(v[at1][at2])continue;
			v[at1][at2]=1;
			for(int i=0;i<g[at1][at2].size();i++){
				int tr=g[at1][at2][i].first.first;
				int tc=g[at1][at2][i].first.second;
				double val=g[at1][at2][i].second;
				if(!v[tr][tc]&&ijk[tr][tc]>cost+val+EPS){
					ijk[tr][tc]=cost+val;
					Q.push(make_pair(-ijk[tr][tc],make_pair(tr,tc)));
				}
			}
		}
		if(ijk[d1][d2]>999999998)printf("-1\n");
		else printf("%f\n",ijk[d1][d2]);
	}
}