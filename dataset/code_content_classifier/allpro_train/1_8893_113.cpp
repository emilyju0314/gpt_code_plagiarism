#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int n,k,s[200005],ans=0;
int main(){
	cin>>n>>k;
	for(int i=1,x;i<=n;i++)cin>>x,s[i]=s[i-1]+x;
	for(int i=k;i<=n;i++)ans=max(ans,s[i]-s[i-k]);
	printf("%.10lf\n",1.0*(ans+k)/2);
}