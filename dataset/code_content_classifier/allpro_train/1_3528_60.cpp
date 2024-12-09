#include<iostream>
using namespace std;
int main(){
	int n,d;
	cin>>n>>d;
	int c=0;
	for(int i=d+1; i<=n+d; i+=2*d+1)c++;
	cout<<c;
}