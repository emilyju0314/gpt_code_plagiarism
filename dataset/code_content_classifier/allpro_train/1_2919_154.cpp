
 #include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#define ll long long 
using namespace std;
ll dp[51][51][101];
int arr[51];
ll solve (int cura,int curb,int rem)
{
	
	if(rem<=0||cura>curb)return 0;
	if(dp[cura][curb][rem]!=-1)return dp[cura][curb][rem];
	ll x= solve(cura,curb,rem-1);
	x=max(x,max(solve(cura+1,curb,rem-1)+arr[cura],solve(cura+1,curb,rem-2)));
	x=max(x,max(solve(cura,curb-1,rem-1)+arr[curb],solve(cura,curb-1,rem-2)));
	return dp[cura][curb] [rem]=x;
}
int main()
{
int n,k;
cin>>n>>k;
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
cout<<solve(0,n-1,k);
    return 0;
}