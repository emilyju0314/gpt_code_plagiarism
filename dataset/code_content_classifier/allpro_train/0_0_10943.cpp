#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n < 3 || m >= n) {
        cout << 0 << endl;
    } else {
        long long answer = 0;
        for (int i = m + 1; i <= n - m; i++) {
            answer += (i - m) * (n - i - m);
        }
        cout << answer << endl;
    }

    return 0;
}