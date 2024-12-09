#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map> 
using namespace std;
typedef long long ll;
//#define int long long
#define bug(i) cout<<"++"<<i<<endl
#define bug1(i,j) cout<<"++"<<i<<"  "<<j<<endl
#define MEM(arr,w) memset(arr,w,sizeof(arr));
const int N=1e5+2100;
const int INF=1e9;
int n,m,t,k;
int ans=0;
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=3)
		{
			cout<<n-1<<endl;
		}
		else
		{
			if(n%2)
			{
				cout<<3<<endl;
			}
			else
			{
				cout<<2<<endl;
			}
		}
	}
	return 0;
}