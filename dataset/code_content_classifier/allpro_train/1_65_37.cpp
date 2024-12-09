#include<iostream>
#include<algorithm>
#include<limits>
#include<cmath>
using namespace std;
int N,M;
int n[51],m[51];
int nx[51],ny[51];
int cx[51],cy[51];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>nx[i]>>ny[i];
	}
	for(int i=1;i<=M;i++){
		cin>>cx[i]>>cy[i];
	}
	for(int i=0;i<N;i++){
		int mi,mid=1000000000;
		for(int j=1;j<=M;j++){
			if(abs(nx[i]-cx[j])+abs(ny[i]-cy[j])<mid){
				mid=abs(nx[i]-cx[j])+abs(ny[i]-cy[j]);
				mi=j;
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}