#include<iostream>
using namespace std;

int gcd(int x,int y){
	int r=x%y;
	if(r==0){
		return y;
	}
	else{
		gcd(y,x%y);
	}
}

int main(){
	int W,H,C;
	cin>>W>>H>>C;
	
	int sq=0;
	
	sq=W/gcd(W,H);
	sq*=H/gcd(W,H);
	
	cout<<sq*C<<endl;
	
	return 0;
}