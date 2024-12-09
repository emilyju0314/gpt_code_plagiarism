#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        int operations = 0;
        for (int i = 1; i < n; i++) {
            if (sequence[i] < sequence[i-1]) {
                operations = max(operations, sequence[i-1] - sequence[i]);
                sequence[i] = sequence[i-1];
            }
        }

        cout << operations << endl;
    }

    return 0;
}