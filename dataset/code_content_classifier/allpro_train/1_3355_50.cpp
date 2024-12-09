#include<iostream>
#include<algorithm>
using namespace std;
int N;
long A[1<<17],ans,now;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	if(N%2==0)
	{
		int t=N/2;
		for(int i=0;i<t;i++)
		{
			long k=i==t-1?1:2;
			ans-=k*A[i];
			ans+=k*A[N-i-1];
		}
	}
	else
	{
		int t=N/2;
		for(int i=0;i<t-1;i++)
		{
			ans-=2*A[i];
			ans+=2*A[N-i-1];
		}
		now=ans;
		ans+=A[t+1]+A[t]-2*A[t-1];
		now+=2*A[t+1]-A[t]-A[t-1];
		if(ans<now)ans=now;
	}
	cout<<ans<<endl;
}
