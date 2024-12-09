#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	int p,max=0,total=0;
	
	cin>>n;
	while(n--){
		cin>>p;
		if(max<p)max=p;
		total+=p;
	}
	cout<<total-max/2<<endl;
	
	return 0;
}
