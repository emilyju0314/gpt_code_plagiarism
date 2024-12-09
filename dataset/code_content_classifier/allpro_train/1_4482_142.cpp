#include<iostream>
using namespace std;
int main(){
	int a,ccount;
	ccount=0;
	cin>>a;
	for(int i=1;i<=a;i=i+2){
		int count=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				count++;
			}
		}
		if(count==8){ccount++;}
	}
	cout<<ccount<<endl;
}