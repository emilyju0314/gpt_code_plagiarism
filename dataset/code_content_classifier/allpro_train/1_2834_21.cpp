#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
	int a1,a2,a3,b1,b2,b3,c1,c2,c3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3;
	if(a1+b2+c3==a1+b3+c2&&a1+b3+c2==a2+b1+c3&&a2+b1+c3==a2+b3+c1&&a2+b3+c1==a3+b1+c2&&a3+b1+c2==a3+b2+c1)puts("Yes");
	else puts("No");
}