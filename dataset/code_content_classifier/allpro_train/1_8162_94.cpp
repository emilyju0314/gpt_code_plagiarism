#include <iostream>
using namespace std;

int main()
{
	int t;
	long long int c1,c2,c3;
	long long int a1,a2,a3,a4,a5;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>c1>>c2>>c3;
		cin>>a1>>a2>>a3>>a4>>a5;
		if(c1-a1>=0)
		c1=c1-a1;
		else
		goto level1;
		if(c2-a2>=0)
		c2=c2-a2;
		else
		goto level1;
		if(c3-a3>=0)
		c3=c3-a3;
		else
		goto level1;
		if(c2+c3-a5>=0)
		{
			if(c2<=a5)
			c3=c3+c2-a5;
		}
		else
		{
			goto level1;
		}
		if(c1+c3-a4>=0)
		{
			if(c1<=a4)
			c3=c3+c1-a4;
			goto level2;
		}
		else
		{
			goto level1;
		}
		
		level1:
		cout<<"NO"<<endl;
		continue;
		
		level2:
		cout<<"YES"<<endl;
		continue;
	}
}