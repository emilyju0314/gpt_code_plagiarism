#include<bits/stdc++.h>
using namespace std;
#define INF -50001
int main(){
int n,m;
cin>>n>>m;
//n本　i回目 残りk本
vector<vector<vector<int> > > dp(n+2,vector<vector<int> >(m+1,vector<int>(9,INF)));
dp[0][m][0]=0;
//for(int i=0;i<9;i++)for(int j=0;j<m+2;j++)for(int k=0;k<m+1;k++)cout<<dp[i][j][k]<<' ';
vector<int> a(n),b(n),c(n);
for(int i=0;i<n;i++){
int d,e,f;
cin>>d>>e>>f;
a[i]=d;
b[i]=e;
c[i]=f;
//cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
}
for(int i=0;i<n;i++){
	for(int j=0;j<m+1;j++){
		for(int k=0;k<9;k++){
			int tmp =dp[i][j][k];
			if(tmp==INF)continue;
			for(int l=0;l<min(j,8)+1;l++){
				for(int x = 0;x<=l;x++){
					for(int y=0;y<=min(k,8-x);y++){
						int cost=0;
						if(x+y==0)cost=c[i];
						else cost=x*a[i]+y*b[i];
						dp[i+1][j-l][l]=max(dp[i+1][j-l][l],dp[i][j][k]+cost);
					}
		
				}

			}
		//	else cout<<i<<' '<<j<<' '<<k<<endl;
			/*for(int t=0;t<9;t++){
				int tmp2;
				if(t+k<=8)tmp2 =t*max(a[i],0)+k*max(b[i],0);
				else tmp2=max((8-k)*max(a[i],0)+k*max(b[i],0),t*max(a[i],0)+max((8-t),0)*b[i]);
				if(j-t>=0){
				int tmp3=0;
				if(tmp2==0)tmp3=c[i];
			 dp[i+1][j-t][t]=max(dp[i+1][j-t][t],tmp+max(tmp2+tmp3,c[i]));
				}
			}*/
		}
	}
}
int ans =INF;
for(int i=0;i<m+1;i++){
for(int j=0;j<9;j++){
	//cout<<dp[n-1][i][j]<<' '<<dp[n][i][j]<<' '<<i<<' '<<j<<endl;
	ans=max(dp[n][i][j],ans);
	
}

}


cout<<ans<<endl;


}

