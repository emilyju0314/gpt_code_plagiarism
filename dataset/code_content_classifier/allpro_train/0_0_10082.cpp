#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> left(m+1, 0);
    vector<int> right(m+1, 0);

    for (int i = 0; i < n; i++) {
        if (left[colors[i]] == 0) {
            left[colors[i]] = 1;
            cout << colors[i] << " " << m << endl;
        } else {
            for (int j = 1; j <= m; j++) {
                if (left[j] == 0) {
                    left[j] = 1;
                    cout << j << " " << colors[i] << endl;
                    break;
                }
            }
        }
        right[colors[i]] = 1;
    }

    return 0;
}