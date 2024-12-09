#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> row_temps(n);
    vector<int> col_temps(m);

    for (int i = 0; i < n; i++) {
        cin >> row_temps[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> col_temps[i];
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        vector<int> good_components;
        vector<int> bad_components;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (row_temps[j] + col_temps[k] >= x) {
                    good_components.push_back(1);
                } else {
                    bad_components.push_back(1);
                }
            }
        }

        int good_score = good_components.size();
        int bad_score = bad_components.size();

        cout << good_score - bad_score << endl;
    }

    return 0;
}