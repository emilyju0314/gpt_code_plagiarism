#include<bits/stdc++.h>
#define ll long long
#define mo 1000000007
#define N 200010
using namespace std;
int n,m,a[N],b[N],nb;
ll dp[N],s[N],ans;
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){char ch=getchar();while (ch!='R'&&ch!='B')ch=getchar();a[i]=(ch=='R');}
	for (int la=0,i=1;i<=m;i++)if (a[i]!=a[1]){b[++nb]=i-la-1;la=i;}
	if (nb==0){
		s[0]=s[1]=ans=1;
		for (int i=2;i<n;i++)s[i]=(s[i-1]+s[i-2])%mo;
		for (int j=0;j<n-1;j++)ans=(ans+s[j])%mo;ans=(ans+s[n-2])%mo;
	}else{
		int ma=b[1];
		for (int i=2;i<=nb;i++)if (b[i]%2)ma=min(ma,b[i]);
		if (ma%2==0)ma++;ma++;
		dp[0]=1;s[0]=1;
		for (int i=1;i<=n;i++){
			if (i%2)dp[i]=0;
			else{dp[i]=s[i-1];if (i-ma-1>=0)dp[i]=(dp[i]-s[i-ma-1]+mo)%mo;}
			s[i]=(s[i-1]+dp[i])%mo;
		}
		for (int j=n-2;j>=0;j-=2)if (n-j<=ma)ans=(ans+dp[j]*(n-j))%mo;
	}
	cout<<ans<<endl;
	return 0;
}