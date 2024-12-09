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

    long long totalMoves = 0;
    for (int k = 1; k < n; k++) {
        int moves = 0;
        for (int i = 0; i < k; i++) {
            int dist = k - i;
            if (a[i] > 0) {
                int t = (a[i] + dist - 1) / dist;
                moves += t;
                a[i] -= t;
                a[k] += t;
            }
        }
        totalMoves += moves;
        cout << totalMoves << endl;
    }

    return 0;
}