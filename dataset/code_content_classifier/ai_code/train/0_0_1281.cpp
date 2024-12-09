#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> switches(n);
    for (int i = 0; i < n; i++) {
        cin >> switches[i];
    }

    for (int i = 0; i < n; i++) {
        bool can_ignore = true;
        for (int j = 0; j < m; j++) {
            if (switches[i][j] == '1') {
                bool all_on = true;
                for (int k = 0; k < n; k++) {
                    if (k != i && switches[k][j] == '0') {
                        all_on = false;
                        break;
                    }
                }
                if (all_on) {
                    can_ignore = false;
                    break;
                }
            }
        }
        if (can_ignore) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}