#include <bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------------------------------//
#define pb push_back
#define F first
#define S second
#define int long long int
#define MOD 1000000007
//--------------------------------------------------------------------------------------//
 
signed main()
{
 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
 	freopen("input.txt", "r" , stdin);
 	freopen("output.txt", "w" , stdout); 
#endif 
 	
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n;
 		cin >> n;

 		int a[n];
 		for(int i=0 ; i<n ; i++)
 			cin >> a[i];

 		int ans = a[0] + a[n-1];
 		for(int i=1 ; i<n ; i++)
 			ans += abs(a[i]-a[i-1]);
 		
 		if(n==1)
 			ans = a[0];
 		else
 		{
 			if(a[0]>a[1])
 			{
 				ans -= (a[0]-a[1]);
 				a[0] = a[1];
 			}

 			for(int i=1 ; i<n-1 ; i++)
 			{
 				if( a[i] > max( a[i-1] , a[i+1] ) )
 				{
 					ans -= ( a[i] - max(a[i-1] , a[i+1]) );
 					a[i] = max(a[i-1] , a[i+1]);
 				}
 			}

 			if(a[n-1]>a[n-2])
 			{
 				ans -= (a[n-1]-a[n-2]);
 				a[n-1] = a[n-2];
 			}
 		}

 		cout << ans;

 		cout<<"\n";
 	}

 	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}	