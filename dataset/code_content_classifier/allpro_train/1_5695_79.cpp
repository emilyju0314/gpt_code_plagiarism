#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<set>
using namespace std;
#define ll long long
const int N=100008;
ll n,nn,a[N],b[N+N];
ll add(ll x,ll y){while(x<=n+n){b[x]+=y;x+=x&(-x);}return 0;}
ll sum(ll x){ll y=0;while(x>0){y+=b[x];x-=x&(-x);}return y;}
ll pan(ll x)
{
	ll i,j,k;
	k=0;
	add(n+1,1);j=0;for(i=1;i<=n;i++){j+=(a[i]<=x);k+=sum(n+j+j-i);add(n+j+j-i+1,1);}
	add(n+1,-1);j=0;for(i=1;i<=n;i++){j+=(a[i]<=x);add(n+j+j-i+1,-1);}
	return k;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	ll i,left,right,mid;
	cin>>n;for(i=1;i<=n;i++)cin>>a[i];
	nn=(n+n*(n-1)/2)/2;
	left=1;right=1000000000;
	while(left+1<right)
	{
		mid=(left+right)>>1;
		if(pan(mid)>nn)right=mid;else left=mid+1;
	}
	if(pan(left)>nn)right=left;
	cout<<right;
	return 0;
}