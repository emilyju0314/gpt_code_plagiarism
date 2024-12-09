#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	int ans=100;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int pow=0;
		while(a[i]%2==0){
			pow++;
			a[i]=a[i]/2;
		}
		if(ans>pow)ans=pow;
	}
	cout<<ans<<endl;
	return 0;
}
