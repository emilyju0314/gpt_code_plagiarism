#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result(n);
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);

    for (int i = 1; i <= n; i++) {
        cout << n - 1 << endl;
        for (int j = 0; j < n; j++) {
            if (indices[j] == i) continue;
            cout << indices[j] << " ";
        }
        cout << endl;
        cout.flush();

        vector<int> minValues(n);
        for (int j = 0; j < n; j++) {
            cin >> minValues[j];
        }

        result[i - 1] = *min_element(minValues.begin(), minValues.end());
    }

    cout << -1 << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}