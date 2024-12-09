#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = i/2 + n/2 + 1;
            } else {
                result[i] = i/2 + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}