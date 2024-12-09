#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long Q,H,S,D,N;
	cin >> Q >> H >> S >> D >> N;
	Q*=4; H*=2;
	S = min({Q,H,S});
	D = min({2*S,D});
	cout << (N/2)*D + (N%2)*S << endl;
	return 0;
}