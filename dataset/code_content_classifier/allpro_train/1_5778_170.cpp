#include<iostream>

using namespace std;

int main() {
	int N, H, W;
	cin >> N >> H >> W;
	int ans = (1 + N - H) * (1 + N - W);
	cout << ans << endl;
}