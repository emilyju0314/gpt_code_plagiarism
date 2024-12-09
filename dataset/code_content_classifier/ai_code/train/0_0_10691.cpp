#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    int operations = 0;
    for (int j = 0; j < m; j++) {
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            if (table[i] > table[i+1]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            operations++;
            for (int i = 0; i < n; i++) {
                table[i].erase(j, 1);
            }
            j--; // Since one column has been removed, we need to check the same column again
        }
    }

    cout << operations << endl;

    return 0;
}