#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n, 1);
    vector<int> colorfulness(n, 0);

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l-1; j < r; j++) {
                colorfulness[j] += abs(x - colors[j]);
                colors[j] = x;
            }
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for (int j = l-1; j < r; j++) {
                sum += colorfulness[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}