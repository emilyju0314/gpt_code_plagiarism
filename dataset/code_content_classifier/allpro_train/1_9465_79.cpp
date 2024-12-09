#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
typedef long long ll;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
		{
		     int x,y;
		     cin>>x>>y;
		     int mn=min(x,y),mx=max(x,y);
		     if(x==y)
		          cout<<2*x<<endl;
		     else
		     {int steps=mn*2+1;
		     cout<<steps+(mx-mn-1)*2<<endl;}
		}
	return  0;
}