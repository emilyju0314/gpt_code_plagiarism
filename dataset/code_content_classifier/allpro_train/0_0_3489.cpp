#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> pairs;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] - x <= b[j] && b[j] <= a[i] + y) {
            pairs.push_back(make_pair(i+1, j+1));
            i++;
            j++;
        } else if (b[j] < a[i] - x) {
            j++;
        } else {
            i++;
        }
    }

    cout << pairs.size() << endl;
    for (auto pair : pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}