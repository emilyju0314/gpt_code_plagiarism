#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N, Q;
    cin >> N >> Q;
    long long sum = 0;
    for (int i = 0; i < Q; i++) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            sum += k;
            sum %= N;
        } else {
            cout << (sum + k - 1) % N + 1 << endl;
        }
    }
    return 0;
}

