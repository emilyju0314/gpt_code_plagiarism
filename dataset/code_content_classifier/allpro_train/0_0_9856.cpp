#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;

    int ans = 1;
    for (int i = 2; i * i <= M; i++) {
        if (M % i == 0) {
            int cnt = 0;
            while (M % i == 0) {
                M /= i;
                cnt++;
            }
            ans = max(ans, i);
        }
    }

    if (M > 1) {
        ans = max(ans, M);
    }

    cout << ans << endl;

    return 0;
}