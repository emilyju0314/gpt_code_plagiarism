#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> group1(n);
    vector<int> group2(m);

    for (int i = 0; i < n; i++) {
        cin >> group1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> group2[i];
    }

    sort(group1.begin(), group1.end());
    sort(group2.begin(), group2.end());

    int max_destroyed = 0;
    for (int i = 0; i <= 100; i++) {
        int destroyed = 0;
        for (int j = 0; j < n; j++) {
            if (binary_search(group1.begin(), group1.end(), group1[j] + i) || binary_search(group2.begin(), group2.end(), group1[j] + i)) {
                destroyed++;
            }
        }
        for (int j = 0; j < m; j++) {
            if (binary_search(group1.begin(), group1.end(), group2[j] - i) || binary_search(group2.begin(), group2.end(), group2[j] - i)) {
                destroyed++;
            }
        }
        max_destroyed = max(max_destroyed, destroyed);
    }

    cout << max_destroyed << endl;

    return 0;
}