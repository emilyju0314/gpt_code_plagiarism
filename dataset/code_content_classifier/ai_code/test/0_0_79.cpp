#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> jumps(n+1, -1);
    jumps[0] = 0;

    for (int i = 0; i < n; i++) {
        if (jumps[i] == -1) {
            continue;
        }
        for (int j = i + a[i]; j >= 0; j--) {
            if (j + a[j] < n+1 && (jumps[j + a[j]] == -1 || jumps[j + a[j]] > jumps[j] + 1)) {
                jumps[j + a[j]] = jumps[j] + 1;
            }
        }
    }

    if (jumps[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << jumps[0] << endl;
        int current = 0;
        vector<int> result;
        while (current != n) {
            result.push_back(current);
            current += a[current];
        }
        for(int i = 0; i <= jumps[0]; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}