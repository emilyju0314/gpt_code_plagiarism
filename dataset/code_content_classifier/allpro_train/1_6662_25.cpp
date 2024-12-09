#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define inf 1<<29
using namespace std;

int Station[301][301];
pair<int,int> p[20];
int dp[(1<<18)][18];

void init(){
  for(int i=0;i<(1<<17);i++)for(int j=0;j<17;j++)dp[i][j]=inf;
  
  for(int i=0;i<301;i++){
    for(int j=0;j<301;j++){
      if(i==j)Station[i][j]=0;
      else Station[i][j]=inf;
    }
  }
}

int main()
{
  int n,m,l,s,t,a,b,c,x,y;

  while(1){
    cin>>n>>m>>l>>s>>t;
    if(n+m+l+s+t==0)break;
    s--;
    init();
    for(int i=0;i<m;i++){
      cin>>a>>b>>c;
      a--;b--;
      Station[a][b]=c;
      Station[b][a]=c;
    }
    for(int i=0;i<l;i++){
      cin>>p[i].f>>p[i].s;
      p[i].f--;
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  Station[i][j]=min(Station[i][j],Station[i][k]+Station[k][j]);
	}
      }
    }

    dp[0][0]=0;
    for(int i=0;i<l;i++)dp[(1<<i)][i]=Station[s][p[i].f]+p[i].s;

    for(int i=1;i<(1<<l);i++){
      for(int j=0;j<l;j++){
	if((i>>j)%2==1){
	  for(int k=0;k<l;k++){
	    if((i>>k)%2==0){
	      dp[(i|(1<<k))][k]=min(dp[(i|(1<<k))][k],
                               dp[i][j]+Station[p[j].f][p[k].f]+p[k].s);
	    }
	  }
	}
      }
    }
    int ans=0;
    for(int i=1;i<(1<<l)+1;i++){
      for(int j=0;j<l;j++){
	//cout<<dp[i][j]<<" "<<Station[p[j].f][s]<<" "<<i<<" "<<p[j].f<<endl;;
	if((dp[i][j]+Station[p[j].f][s])<=t){
	  int sum=0;
	  for(int k=0;k<l;k++)if((i>>k)%2==1)sum++;
	  ans=max(ans,sum);
	}
      }
    }
    cout<<ans<<endl;;
  }    
  return 0;
}