#include<stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	int i,n,a,j,b,c,d,A[101],B[101]; 
	cin>>n;
	for(i=1;i<=n;i++){
		A[i]=0;
		B[i]=1;
		}
	for(i=0;i<n*(n-1)/2;i++){
		cin>>a>>b>>c>>d;
		if(c>d){
			A[a]+=3;
		}
		else if(c<d){
			A[b]+=3;
		}
		else{
			A[a]++;
			A[b]++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(A[i]>A[j]){
				B[j]++;
			}
		}
	}
	for(i=1;i<=n;i++){
		cout<<B[i]<<endl;
	}
return 0;
}