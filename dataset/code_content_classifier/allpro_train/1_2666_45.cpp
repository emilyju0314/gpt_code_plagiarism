#include<iostream>
using namespace std;

int main(){
	int a,b,k; cin >> a >> b >> k;
	int p=a;
	while(p<=b){
		cout << p << endl;
		p++;
		if(p==a+k && a+(k-1)<b-(k-1)) p=b-(k-1);
	}
}
