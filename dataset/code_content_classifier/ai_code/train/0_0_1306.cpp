#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    vector<int> positions(N + 1);
    for (int i = 0; i < N; i++) {
        positions[Q[i]] = i;
    }

    vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        diff[i] = positions[P[i]] - i;
    }

    int gcd = diff[0];
    for (int i = 1; i < N; i++) {
        gcd = __gcd(gcd, diff[i]);
    }

    cout << (gcd == 0 ? 0 : (gcd > 0 ? gcd : -1)) << endl;

    return 0;
}