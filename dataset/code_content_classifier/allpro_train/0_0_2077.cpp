#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        vector<int> s(N);
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }

        int Xmax = -1;
        int left = 0, right = 1e6;
        while (left <= right) {
            int mid = (left + right) / 2;
            int count = 0;
            int level = 1;

            for (int i = 0; i < N; i++) {
                if (s[i] < level + mid) {
                    count += max(1, mid - abs(level - s[i]));
                    level += max(1, mid - abs(level - s[i]));
                } else {
                    break;
                }
            }

            if (count >= M) {
                Xmax = max(Xmax, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (Xmax == -1) {
            cout << -1 << endl;
        } else {
            cout << Xmax << endl;
        }
    }

    return 0;
}