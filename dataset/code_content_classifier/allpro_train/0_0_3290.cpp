#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> count(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        count[l]++;
        count[r + 1]--;
    }

    vector<int> flowers(n, 0);
    int current = 0;
    for (int i = 0; i < n; i++) {
        current += count[i + 1];
        flowers[i] = current % 2;
    }

    for (int i = 0; i < n; i++) {
        cout << flowers[i];
    }

    return 0;
}