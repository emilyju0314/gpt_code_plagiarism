#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n);
		int avg=sum/n;
		int i=n-1;
		int count=0;
		int j=n;
		bool flag=true;
		while(flag){
			flag=false;
			while (avg<a[i]){
				if(a[i]>avg){
					sum-=a[i];
					i--;
					count++;
					j--;
					avg=sum/j;
					flag=true;
				}
			}
		}
		cout<<count<<endl;
	}
   return 0;
}