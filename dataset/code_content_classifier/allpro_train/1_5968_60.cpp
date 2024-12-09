#include <vector>
#include <iostream>
using namespace std;
int dx[] = { 1, 0, 0, -1, 0, 0 };
int dy[] = { 0, 1, 0, 0, -1, 0 };
int dz[] = { 0, 0, 1, 0, 0, -1 };
int H, W, D, N, a[1009], b[1009], c[1009];
int main() {
	cin >> H >> W >> D >> N;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];
	long long ret = (1LL * H * W + 1LL * W * D + 1LL * D * H) * 2;
	for (int i = 0; i < N; i++) {
		ret += 6;
		for (int j = 0; j < 6; j++) {
			int tx = a[i] + dx[j], ty = b[i] + dy[j], tz = c[i] + dz[j];
			if (!(0 <= tx && tx < H && 0 <= ty && ty < W && 0 <= tz && tz < D)) ret -= 2;
			else {
				for (int k = 0; k < i; k++) {
					if (a[k] == tx && b[k] == ty && c[k] == tz) {
						ret -= 2; break;
					}
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}