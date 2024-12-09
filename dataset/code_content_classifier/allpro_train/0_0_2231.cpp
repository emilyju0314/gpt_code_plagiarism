#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int lcm = A[0];
    for (int i = 1; i < N; i++) {
        lcm = (lcm * A[i]) / gcd(lcm, A[i]);
    }

    int ans = M / (2 * lcm);
    cout << ans << endl;

    return 0;
}