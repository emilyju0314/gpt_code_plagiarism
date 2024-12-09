#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a == 0 && b == 0) {
        if (n == 2) {
            cout << "1 2" << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (a + b > n - 1 || a * b == 0) {
        cout << -1 << endl;
    } else {
        int k = n - a - b;
        vector<int> result;
        for (int i = 0; i < a; i++) {
            result.push_back(n - 1 - i);
        }
        if (b > 0) {
            result.push_back(n);
            b--;
        }
        for (int i = k - 1; i >= 1; i--) {
            result.push_back(i);
        }
        if (b > 0) {
            result.push_back(k + 1);
        }
        for (int i = k + 2; i <= n; i++) {
            result.push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }

    return 0;
}