#include<cstdio>
#include<algorithm> 
#include<vector>
#include<set>
using namespace std;
int a[5][150005],n[5],dp[5][150005];
vector<int> v[150005];
multiset<int> s;
int main(){
	int i,j,k,minn=2147483647;
	for(i=1;i<=4;i++){
		scanf("%d",&n[i]);
	}
	for(i=1;i<=4;i++){
		for(j=1;j<=n[i];j++){
			dp[i][j]=2147483647;
		}
	}
	for(i=1;i<=4;i++){
		for(j=1;j<=n[i];j++){
			scanf("%d",&a[i][j]);
			if(i==1){
				dp[i][j]=a[i][j];
			} 
		}
	}
	for(k=1;k<=3;k++){
		int m;
		while(!s.empty()){
			s.erase(s.begin());
		}
		for(i=1;i<=n[k];i++){
		    s.insert(dp[k][i]);
	    }
		for(i=1;i<=n[k+1];i++){
			v[i].clear();
		}
		scanf("%d",&m);
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			v[y].push_back(x);
		}
		for(i=1;i<=n[k+1];i++){
			int x;
			for(j=0;j<v[i].size();j++){
				s.erase(s.find(dp[k][v[i][j]]));
			}
			if(s.empty()||*s.begin()==2147483647){
				for(j=0;j<v[i].size();j++){
				    s.insert(dp[k][v[i][j]]);
			    }
				continue;
			}
			dp[k+1][i]=*s.begin()+a[k+1][i];
			for(j=0;j<v[i].size();j++){
				s.insert(dp[k][v[i][j]]);
			}
		}
	}
	for(i=1;i<=n[4];i++){
		minn=min(minn,dp[4][i]);
	}
	if(minn==2147483647){
		printf("-1");
		return 0;
	}
	printf("%d",minn);
	return 0;
}
