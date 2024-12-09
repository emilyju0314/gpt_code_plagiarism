#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
#define sp system("pause");
using namespace std;
bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	int cnt,n,i;
	cin>>n;
	for(i=2,cnt=0;cnt<n;i++)
		if(prime(i)&&i%5==1)
			cout<<i<<' ',cnt++;
	return 0;
}