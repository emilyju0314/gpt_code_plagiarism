#include <iostream>

using namespace std;

int solve(int K)
{
	int x = 0;
	for (int i = 1; i <= K; ++i) {
		x = (10 * x + 7) % K;
		if (x == 0) {
			return i;
		}
	}
	return -1;
}

int main()
{
	int K;
	cin >> K;

	cout << solve(K) << endl;
}
