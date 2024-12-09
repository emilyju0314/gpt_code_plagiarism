#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;

        int max_points = 0;
        for (int i = L - 1; i < R; i++) {
            int j = i;
            while (j < R && points[j + 1] - points[i] < K) {
                j++;
            }
            max_points = max(max_points, j - i + 1);
        }

        cout << max_points << endl;
    }

    return 0;
}