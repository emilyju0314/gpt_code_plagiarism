#include <iostream>

using namespace std;

int main(void)
{
	int q,p,n;
	char c;
	long long l,r;
	int i1;

	cin>>q;
	l=0;
	r=0;
	for(i1=0;i1<q;i1++){
		cin>>p>>c>>n;
		if(c=='(') l+=n;
		else r+=n;

		if(l==r) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}