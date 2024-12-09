#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> min_values(n);

    for (int i = 0; i < n; i++) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; j++) {
            if (j != i + 1) {
                cout << j << " ";
            }
        }
        cout << endl;
        cout.flush();

        vector<int> row_values(n);
        for (int j = 0; j < n; j++) {
            cin >> row_values[j];
        }

        min_values[i] = *min_element(row_values.begin(), row_values.end());
    }

    cout << -1 << endl;
    for (int i = 0; i < n; i++) {
        cout << min_values[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}