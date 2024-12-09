#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	if (k<=a)
		cout<<k;
	else if (k>a&&k<=a+b)
		cout<<a;
	else
		cout<<2*a+b-k;
}