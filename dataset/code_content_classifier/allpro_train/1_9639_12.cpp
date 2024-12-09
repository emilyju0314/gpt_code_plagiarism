#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,x;
		cin>>n>>m;
		
		set<int> st1;
		
		for(int i=0;i<n;i++)
		{
			cin>>x;
			
			st1.insert(x);
		}
		
		int count=0;
		
		for(int i=0;i<m;i++)
		{
			cin>>x;
			
			if(st1.count(x))
			count++;
		}
		
		cout<<count<<"\n";
	}
	
	return(0);
}
