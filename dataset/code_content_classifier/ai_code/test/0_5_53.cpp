#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> operations;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                operations.push_back(i);
                for (int j = 0; j < n; j++) {
                    if ((j+1) % i != 0) {
                        s[j] = c;
                    }
                }
            }
        }

        // Print the minimum number of operations required
        cout << operations.size() << endl;
        // Print the x-s that should be used
        for (int x : operations) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}