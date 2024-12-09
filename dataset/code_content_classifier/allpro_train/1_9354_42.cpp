#include <iostream>
#include <utility>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint q, x, a = 1, b = 0;
	for(int i = 0; i < n; i++){
		cin >> q >> x;
		if(q == 1) a *= x, b *= x;
		if(q == 2) b += x;
		if(q == 3) b -= x;
	}
	cout << -b << " " << a << endl;
	
	return 0;
}
