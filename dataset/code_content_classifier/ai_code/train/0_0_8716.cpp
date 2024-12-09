#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long fa = 0, M = 0;
    for (int i = 1; i < n; i++) {
        if (a[M] < a[i]) {
            fa = (fa + a[M]) % MOD;
            M = i;
        }
    }
    cout << fa << endl;

    return 0;
}