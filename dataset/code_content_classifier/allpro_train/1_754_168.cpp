#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	float a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		a[i+1] = (a[i] + a[i+1]) * 1.0 / 2;
	}
	printf("%.6f",a[n-1]);
}