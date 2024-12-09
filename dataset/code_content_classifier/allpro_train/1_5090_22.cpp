#include <iostream>
using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;
	m /= 2;
	long long ans = min(n, m);
	if(n < m){
		ans = max(ans, (m + n) / 2);
	}
	cout << ans << endl;
}