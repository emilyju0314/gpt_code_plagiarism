#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
		cin>>n;
		int sum=n/11;
		int temp=n%11;
		int i=0;
		int ans=0;
		if((n-temp*111)%11==0&&(n-temp*111)>=0)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
		
	}
	return 0;
}