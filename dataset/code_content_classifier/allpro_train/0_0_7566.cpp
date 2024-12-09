#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> winners(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l; j <= r; j++) {
            if (j != x) {
                if (winners[j] == 0) {
                    winners[j] = x;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << winners[i] << " ";
    }

    return 0;
}