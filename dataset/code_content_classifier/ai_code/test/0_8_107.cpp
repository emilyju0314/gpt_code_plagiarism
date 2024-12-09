#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a == 0 && b == 0) {
            if (n == 2) {
                cout << "1 2\n";
            } else {
                cout << "-1\n";
            }
        } else if (a == 0 && b == 1) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << "\n";
        } else if (a == 1 && b == 0) {
            vector<int> permutation;
            permutation.push_back(1);
            for (int i = n; i >= 2; i--) {
                permutation.push_back(i);
            }
            for (int i : permutation) {
                cout << i << " ";
            }
            cout << "\n";
        } else if (a + b <= n - 1 && a * b != 0) {
            vector<int> permutation;
            for (int i = 1; i <= b + 1; i++) {
                permutation.push_back(i);
            }
            int num = b + 2;
            for (int i = 1; i < a; i++) {
                permutation.insert(permutation.begin() + i, num++);
            }
            for (int i = num; i <= n; i++) {
                permutation.push_back(i);
            }
            for (int x : permutation) {
                cout << x << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}