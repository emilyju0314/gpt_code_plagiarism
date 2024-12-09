#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> moves(n-1, 0);

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < k; i++) {
            moves[k-1] += (long long)a[i] * (k - i);
        }
        for (int t = 1; t <= (n-k)/2; t++) {
            a[k+2*t-1] += a[k-1];
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << moves[i] << endl;
    }

    return 0;
}