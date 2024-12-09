#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int> A(N + 1);
	for (int i = 0; i < N; i++) cin >> A[i];
	int NowColor = 1;
	int Rest = A[0];
	for (int i = 0; i < H; i++) {
		vector<int> Row(W);
		for (int j = 0; j < W; j++) {
			Row[j] = NowColor;
			Rest--;
			if (Rest == 0) {
				NowColor++;
				Rest = A[NowColor - 1];
			}
		}
		if (i % 2 == 0) for (int j = 0; j < W; j++) cout << Row[j] << " ";
		else  for (int j = W - 1; j >= 0; j--) cout << Row[j] << " ";
		cout << endl;
	}
}