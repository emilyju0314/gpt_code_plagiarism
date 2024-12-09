#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int r,c,k;
int fie[1005][1005];
PP p[1000005];
int dp[1005][1005];
int maxi[1005][1005];

int main(void){
	scanf("%d%d%d",&r,&c,&k);
	for(int i=0;i<r;i++){
		string s;
		cin >> s;
		for(int j=0;j<c;j++){
			if(s[j]=='#'){
				fie[i][j]=1;
			}
			p[i*c+j]=PP(i+j,P(i,j));
		}
	}
	sort(p,p+r*c);
	queue<P> que;
	for(int i=0;i<r*c;i++){
		que.push(p[i].second);
	}
	memset(maxi,-1,sizeof(maxi));
	while(que.size()){
		P p=que.front();
		que.pop();
		int x=p.second,y=p.first;
		if(x>0){
			maxi[y][x]=max(maxi[y][x],maxi[y][x-1]);
		}
		if(y>0){
			maxi[y][x]=max(maxi[y][x],maxi[y-1][x]-1);
		}
		if(fie[y][x]==1)continue;
		if(x<=maxi[y][x]){
			dp[y][x]=1;
		}else{
			dp[y][x]=0;
			maxi[y][x]=x+k;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			//printf("%d ",dp[i][j]);
		}
		//printf("\n");
	}
	printf("%s\n",dp[r-1][c-1]==1?"Chieno":"Cacao");
	return 0;
}

