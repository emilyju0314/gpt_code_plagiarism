#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	long long k=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		k*=i;
	}
	cout<<k<<endl;
	return 0;
	}

