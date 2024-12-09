#include <bits/stdc++.h>
using namespace std;
int a[109];
int main() {
	int n; cin>>n;
	for (int i=0;i<n; i++)cin>>a[i];
		for (int k=0;k<n-1;k++)cout<<a[k]<<" ";
		cout<<a[n-1]<<endl;
	for (int i=1;i<n;i++){
		int key = a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){a[j+1]=a[j];j--;}
		a[j+1]=key;
		for (int k=0;k<n-1;k++)cout<<a[k]<<" ";
		cout<<a[n-1]<<endl;
	}
	// 10 min
	return 0;
}