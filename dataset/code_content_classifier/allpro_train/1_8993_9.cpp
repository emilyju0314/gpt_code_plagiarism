#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[120][120],B;
int main(){
	while(true){
		cin>>n;
		if(n==0){break;}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				B=0;
				for(int k=0;k<n;k++){
					if(a[i][j]>a[i][k] || a[i][j]<a[k][j])B=1;
				}
				if(B==0){
					cout<<a[i][j]<<endl;goto E;
				}
			}
		}
		cout<<"0"<<endl;E:;
	}
	return 0;
}