#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N, M_a, M_b;
    cin >> N >> M_a >> M_b;

    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int g = gcd(M_a, M_b);
    int total_a = M_a / g;
    int total_b = M_b / g;
    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 40; j++) {
            for (int k = 1; k <= 40; k++) {
                if (j * a[i] >= total_a && k * b[i] >= total_b) {
                    ans = min(ans, j * c[i] + k * c[i]);
                }
            }
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}