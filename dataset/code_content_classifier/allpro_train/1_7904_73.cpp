#include<bits/stdc++.h>
#define ll long long int
#define mii map<int,int>
#define qi queue<int>
#define pqi priority_queue<int>
#define pqgi priority_queue<int,vector<int>,greater<int>>
#define si set<int>
#define vi vector<int>
#define vll vector<long long int>
#define vii vector<pair<int,int>>
#define mii map<int,int>
#define ii pair<int,int>
#define SYNC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for(int i=a;i<b;i++)
#define rf(j,c,d) for(int j=c;j>d;j--)
#define mod 1000000007
#define mo 998244353
#define inf 1e18
#define F first
#define S second
#define ld long double
#define INF (int)INT_MAX
#define PI 3.1415926535898
using namespace std;
const int N=1e5+5;
clock_t timeStart, timeFinish;
void timeBegin(){
	timeStart = clock();
}
void timeEnd() {
    timeFinish = clock();
}
void timeDuration() {
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}
/*ll po(ll A,ll B)
{
	ll RES=1;
	while(B)
	{
		if(B&1)
			RES*=A;
		B>>=1;
		A*=A;
	}
	return RES;
}*/
void solve()
{
	int n,m;
	cin>>n>>m;
	string s[n+1];int arr[n+1][n+1];
	int x=-1,y=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<n;j++)
		{
			if(i!=j+1)
				arr[i][j+1]=(int)(s[i][j]-'a')+1;
			else arr[i][j+1]=0;
			if(j+1<i&&arr[i][j+1]==arr[j+1][i])
			{
				x=i,y=j+1;
			}
		}
	}
	if(m%2)
	{
		cout<<"YES\n";
		for(int i=1;i<=m+1;i++)
		{
			if(i%2)
				cout<<"1 ";
			else cout<<"2 ";
		}
		cout<<'\n';
		return;
	}
	if(x!=-1&&y!=-1)
	{
		cout<<"YES\n";
		for(int i=1;i<=m+1;i++)
		{
			if(i%2)
				cout<<x<<" ";
			else cout<<y<<" ";
		}
		cout<<'\n';
		return;
	}
	int z=-1,w=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=n;k++)
			{
				if(i==k||j==k)continue;
				if(arr[i][j]==arr[j][k])
				{
					x=i,y=j,z=k;
					w=0;
					break;
				}
			}
			if(!w)break;
		}
		if(!w)
			break;
	}
	if(w)
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	if(m%4==0)
	{
		cout<<y<<" ";
		for(int i=1;i<=m/4;i++)
		{
			cout<<z<<" "<<y<<" "<<x<<" "<<y<<" ";
		}
		cout<<'\n';
	}
	else
	{
		for(int i=1;i<=m+1;i++)
		{
			if(i%4==1)
				cout<<x<<" ";
			else if(i%4==2)
				cout<<y<<" ";
			else if(i%4==3)
				cout<<z<<" ";
			else cout<<y<<" ";
		}
		cout<<'\n';
	}
	return;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
	#endif
	SYNC
    //sieve();
    int t=1;
    cin>>t;
    while(t--)
    	solve();
    //timeDuration();
    return 0;
}