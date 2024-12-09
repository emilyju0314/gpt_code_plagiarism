#include<iostream>
using namespace std;
int a[210];
int main() {
	a[1] = 300000;
	a[2] = 200000;
	a[3] = 100000;
	int x, y;
	cin >> x >> y;
	if (x == 1 && y == 1) {
		cout << a[x] + a[y] + 400000;
	}
	else
		cout << a[x] + a[y];
	return 0;
}