#include <iostream>

using namespace std;

void solve(int a, int b, int c) {
	int sum = a + b;
	float prob = 0.0f;
	for (int n = 1; n <= 10; n++) {
		if (n == a || n == b || n == c) continue;
		if (sum + n <= 20) prob += 1.0f / 7.0f;
	}
	if (prob >= 0.5f)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c;
	while (cin >> a >> b >> c)
		solve(a, b, c);

}