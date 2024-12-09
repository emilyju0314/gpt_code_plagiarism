#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> y1(n);
    vector<int> y2(m);

    for (int i = 0; i < n; i++) {
        cin >> y1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> y2[i];
    }

    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());

    int maxDestroyed = max(y1[n-1], y2[m-1]) - min(y1[0], y2[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int destroyed = max(y1[n-1], y2[j]) - min(y1[i], y2[0]);
            maxDestroyed = max(maxDestroyed, destroyed);
        }
    }

    cout << maxDestroyed << endl;

    return 0;
}