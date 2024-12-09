#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a == 0 && b == 0) {
        if (n == 2) {
            cout << "1 2\n";
        } else {
            cout << "-1\n";
        }
        return;
    }

    if (a == 0 || b == 0 || a + b >= n || a + b < n - 1) {
        cout << "-1\n";
        return;
    }

    vector<int> result;
    int numIncreasing = n - b;

    for (int i = 0; i < numIncreasing; i++) {
        result.push_back(i + 1);
    }

    for (int i = numIncreasing; i > numIncreasing - b; i--) {
        result.push_back(i);
    }

    for (int i = numIncreasing + 1; i <= n; i++) {
        result.push_back(i);
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        solve(n, a, b);
    }

    return 0;
}