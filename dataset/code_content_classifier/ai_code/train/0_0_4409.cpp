#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> scents(N);
    for (int i = 0; i < N; i++) {
        cin >> scents[i];
    }

    int ans = -1;
    for (int R = 0; R <= N; R++) {
        long long totalSum = 0;
        int maxScent = 0;
        for (int i = 0; i < N; i++) {
            int start = max(i - R, 0);
            int end = min(i + R, N - 1);
            for (int j = start; j <= end; j++) {
                totalSum += max(0, scents[j] - abs(i - j) * C);
                maxScent = max(maxScent, scents[j]);
            }
        }
        if (totalSum >= M) {
            ans = R;
            break;
        }
        if (maxScent <= C * (2 * R + 1)) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}