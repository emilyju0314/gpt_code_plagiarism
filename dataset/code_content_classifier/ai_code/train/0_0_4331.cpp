#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    vector<int> r(K);
    vector<int> b(K);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < K; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < K; i++) {
        cin >> b[i];
    }

    sort(r.begin(), r.end());
    sort(b.begin(), b.end());

    int changes = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] <= r[0] + b[0]) {
            if (r[0] < b[0]) {
                if (r[0] < b[1] || a[i] <= b[0] + b[1]) {
                    changes += max(0, a[i] - r[0]);
                } else {
                    changes += a[i] - b[0] - b[1];
                }
            } else {
                if (b[0] < r[1] || a[i] <= r[0] + r[1]) {
                    changes += max(0, a[i] - b[0]);
                } else {
                    changes += a[i] - r[0] - r[1];
                }
            }
        } else {
            changes = -1;
            break;
        }
    }

    cout << changes << endl;

    return 0;
}