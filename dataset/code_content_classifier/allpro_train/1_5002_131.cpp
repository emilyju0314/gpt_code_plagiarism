#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int32_t n;
    cin >> n;
    int32_t a[n], b[n], c[n];

    for (int32_t i = 0; i < n; i++) { cin >> a[i]; }
    for (int32_t i = 0; i < n; i++) { cin >> b[i]; }
    for (int32_t i = 0; i < n; i++) { cin >> c[i]; }
    sort(a, a + n);
    sort(c, c + n);

    int64_t answer = 0;
    for (int32_t i = 0; i < n; i++) {
        answer += (lower_bound(a, a + n, b[i]) - a) * (n - (lower_bound(c, c + n, b[i] + 1) - c));
    }

    cout << answer << endl;

    return 0;
}
