#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int time[n+1];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>time[i];
		sum+=time[i];
	}
	int k;
	cin>>k;
	int p,x;
	for(int i=0;i<k;i++){
		cin>>p>>x;
		cout<<sum-time[p-1]+x<<endl;
	}
	return 0;
}