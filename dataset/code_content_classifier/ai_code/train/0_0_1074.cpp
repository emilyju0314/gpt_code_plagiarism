#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n || (n/k < 3 && n/k != 2)) {
        cout << -1 << endl; // no solution possible
    } else {
        vector<int> secret(n);
        int keeper = 1;
        
        for (int i = 0; i < n; i++) {
            secret[i] = keeper;
            keeper = (keeper % k) + 1;
        }

        for (int i = 0; i < n; i++) {
            cout << secret[i] << " ";
        }
        cout << endl;
    }

    return 0;
}