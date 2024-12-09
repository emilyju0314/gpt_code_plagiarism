#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int p = 998244353;

int main() {
    int k;
    cin >> k;

    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    int n, m;
    cin >> n >> m;

    if (n <= k) {
        cout << 1 << endl;
        return 0;
    }

    long long fk = -1;
    for (int f = 1; f < p; f++) {
        long long fn = 1;
        vector<int> sequence(k, 1);
        for (int i = k; i < n; i++) {
            int next = 0;
            for (int j = 0; j < k; j++) {
                next = (next + (long long) sequence[j] * b[j]) % p;
            }
            sequence.erase(sequence.begin());
            sequence.push_back(f);
            fn = (fn * next) % p;
        }
        if (fn == m) {
            fk = f;
            break;
        }
    }

    cout << fk << endl;

    return 0;
}