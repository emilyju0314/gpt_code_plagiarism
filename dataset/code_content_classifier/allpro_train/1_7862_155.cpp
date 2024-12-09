#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	sort(a.begin(),a.end());
	int sum = 0;
	for(auto &i:a)sum+= i;
	for(int i =0;i<n;i++)
	{
		if(sum%10)
		{
			cout<<sum<<endl;
			return 0;
		}
		if(a[i]%10)sum-=a[i];
	}
	if(sum%10)cout<<sum<<endl;
	else cout<<0<<endl;
	
}
