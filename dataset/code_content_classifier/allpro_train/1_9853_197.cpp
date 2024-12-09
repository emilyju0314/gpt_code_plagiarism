#include <iostream>

using namespace std;
int main(){
	long long n,a,b;
	cin >> n >> a >> b;
	if(!((b - a)&1)){
		cout << (b - a)/2 << endl;
	}else{
		cout << (b - a + 1)/2 + min(a - 1,n - b) << endl;
	}
}