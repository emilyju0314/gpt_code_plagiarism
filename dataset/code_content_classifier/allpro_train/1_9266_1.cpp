#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long dp[2][2020];
vector<pair<pair<long long,long long>,pair<long long,long long> > >E;
int main()
{
	cin>>N;
	for(int i=0;i<=2000;i++)dp[0][i]=-1e18;
	for(int i=0;i<N;i++)
	{
		long long R,A,W,T;
		cin>>R>>A>>W>>T;
		T--;
		E.push_back({{T,R},{A,W}});
	}
	sort(E.begin(),E.end(),[](
	pair<pair<long long,long long>,pair<long long,long long> >a,
	pair<pair<long long,long long>,pair<long long,long long> >b
	){return a.first.first+a.first.second>b.first.first+b.first.second;}
	);
	for(int i=0;i<N;i++)
	{
		long long R,A,W,T;
		R=E[i].first.second;
		A=E[i].second.first;
		W=E[i].second.second;
		T=E[i].first.first;
		for(int j=0;j<=2000;j++)dp[1][j]=-1e18;
		for(int j=R;j<=2000;j++)
		{
			dp[1][min(T,j-R)]=max(dp[1][min(T,j-R)],dp[0][j]+A);
		}
		dp[1][T]=max(dp[1][T],A);
		for(int j=T;j>=R;j--)
		{
			dp[1][j-R]=max(dp[1][j-R],dp[1][j]+W);
		}
		for(int j=0;j<=2000;j++)dp[0][j]=max(dp[0][j],dp[1][j]);
	}
	long long ans=0;
	for(int j=0;j<=2000;j++)ans=max(ans,dp[0][j]);
	cout<<ans<<endl;
}

