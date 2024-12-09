#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        bool found = false;
        vector<int> factors;

        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                factors.push_back(j);
                n /= j;

                if (factors.size() == 2) {
                    factors.push_back(n);
                    found = true;
                    break;
                }
            }
        }

        if (found && factors[0] != factors[1] && factors[0] != factors[2] && factors[1] != factors[2]) {
            cout << "YES" << endl;
            for (int j = 0; j < 3; j++) {
                cout << factors[j] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}