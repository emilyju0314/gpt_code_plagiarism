#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K,p[1001];
	int sum = 0;
	cin>>N>>K;
	for(int i=0;i<N;i++) cin>>p[i];
	sort(p,p+N);
	for(int i=0;i<K;i++) sum += p[i];
	cout<<sum<<endl;
	return 0;
}