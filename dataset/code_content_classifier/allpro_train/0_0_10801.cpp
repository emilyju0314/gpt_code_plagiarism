#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;

    int ans = 0;
    for (int x = 0; x <= N; x++) {
        int value = floor(1.0 * A * x / B) - A * floor(1.0 * x / B);
        ans = max(ans, value);
    }

    cout << ans << endl;

    return 0;
}