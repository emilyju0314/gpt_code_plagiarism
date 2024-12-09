#include<bits/stdc++.h>
using namespace std;

int a, b;

int GCD(int a, int b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(){
	while(cin >> a >> b){
		cout << GCD(a, b) << endl;
	}
	return 0;
}