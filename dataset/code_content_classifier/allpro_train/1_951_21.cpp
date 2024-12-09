#include<iostream>
using namespace std;
int main(){
	int N,M,a,count=0;
	cin >> N >> M ;
	for(int i=0;i<M;i++){
		cin >> a;
	}
	while(1){
		N = N/2;
		count = count + N;
		if(N==1)	break;
	}
	cout << count-M << "\n";
	return 0;
}