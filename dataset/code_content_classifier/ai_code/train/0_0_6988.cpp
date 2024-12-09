#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int g = A[0];
    for (int i = 0; i < N; i++) {
        g = gcd(g, A[i]);
    }

    int ans = 1;
    for (int i = 0; i < N; i++) {
        ans = max(ans, gcd(g, A[i]));
    }

    cout << ans << endl;

    return 0;
}