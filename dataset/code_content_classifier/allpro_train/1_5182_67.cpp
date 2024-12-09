#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int kin,sum;
	while(1)
	{
		cin>>kin;
		if(kin==0)
			break;
		kin=1000-kin;
		sum=kin/500+(kin%500)/100+(kin%500%100)/50+(kin%500%100%50)/10+(kin%500%100%50%10)/5+(kin%500%100%50%10%5);
		cout<<sum<<endl;
	}
	return 0;
}
