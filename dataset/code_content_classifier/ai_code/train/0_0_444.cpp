#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        queries.push_back({L, R});
    }

    for (int i = 0; i < q; i++) {
        int L = queries[i].first;
        int R = queries[i].second;

        if (R - L < 2) {
            cout << "0" << endl;
        } else {
            bool found = false;
            for (int j = L; j < R - 2; j++) {
                if (a[j] < a[j+1] && a[j+1] > a[j+2]) {
                    cout << "3" << endl;
                    cout << j+1 << " " << j+2 << " " << j+3 << endl;
                    found = true;
                    break;
                } else if (a[j] > a[j+1] && a[j+1] < a[j+2]) {
                    cout << "3" << endl;
                    cout << j+1 << " " << j+2 << " " << j+3 << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}