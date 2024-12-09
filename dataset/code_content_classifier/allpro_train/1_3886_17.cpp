#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<vector>

#define MAX(x,y) ((x>y)?(x):(y))
#define min(x,y) ((x<y)?(x):(y))
typedef long long ll;

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

struct room{
	int x,y,l;
	room(int x0,int y0,int l0){x=x0;y=y0;l=l0;}
	bool operator < (room a) const {return (l>a.l);}
};
int L[2][505][505],f[505][505];
int d[2][250005],e;
int main(){
	int i,j,k;
	int w[2],h[2],r,x[2],y[2],cx,cy;
	int ma,ans;
	priority_queue<room> q;
	
	while(1){
		scanf("%d",&r);
		if(r==0)break;
		memset(L,-1,sizeof(L));
		
		for(k=0;k<2;k++){
			scanf("%d%d%d%d",&w[k],&h[k],&x[k],&y[k]);
			for(i=1;i<=h[k];i++)for(j=1;j<=w[k];j++){
				scanf("%d",&L[k][i][j]);
				
			}
		}
		
		memset(d,-1,sizeof(d));
		for(i=0;i<2;i++){
			memset(f,0,sizeof(f)); 
			f[y[i]][x[i]]=1;
			q.push(room(x[i],y[i],1));
			ma=0;
			e=0;
			d[i][0]=0;
			while(!q.empty()){
				room cr=q.top();
				q.pop();
				e++;
				ma=MAX(ma,cr.l);
				d[i][e]=ma;
				//printf("%d\n",ma);
				for(k=0;k<4;k++){
					cx=cr.x+dx[k];
					cy=cr.y+dy[k];
					if(L[i][cy][cx]>=0 && f[cy][cx]==0){
						q.push(room(cx,cy,L[i][cy][cx]));
						f[cy][cx]=1;
					}
				}
			}
			//printf("END%d\n",i);
			
			/*for(j=1;j<=r;j++){
				//if(d[i][i]==0)d[i][j]=d[i][j-1];
				//printf("%d %3d ->%d\n",i,j,d[i][j]);
			}*/
		}
		ans=100000005;
		for(i=0;i<=w[0]*h[0];i++){
			if(d[0][i]!=-1 && d[1][r-i]!=-1 && r-i>=0 && r-i<=w[1]*h[1])ans=min(ans,d[0][i]+d[1][r-i]);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}