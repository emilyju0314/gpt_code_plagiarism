#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> color(n+1, 0);
    vector<int> colorfulness(n+1, 0);

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l; j <= r; j++) {
                color[j] = x;
                colorfulness[j] += abs(x - j);
            }
        } else if (type == 2) {
            int l, r, sum = 0;
            cin >> l >> r;
            for (int j = l; j <= r; j++) {
                sum += colorfulness[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}