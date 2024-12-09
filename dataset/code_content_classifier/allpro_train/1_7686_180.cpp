#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long n,a,b,c,d,e,minv;
	cin>>n>>a>>b>>c>>d>>e;;
	
	minv=min(a,min(b,min(c,min(d,e))));
	
	cout<<((n%minv==0)? n/minv+4:n/minv+5)<<endl;
	
	return 0;
}
