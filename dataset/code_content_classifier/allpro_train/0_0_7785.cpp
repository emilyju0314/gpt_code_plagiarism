#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int max_pig_meso = 0;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            int umaka_sticks = i, puffs = j;
            for (int k = 0; k < n; k++) {
                int min_sticks = min(a[k], umaka_sticks);
                int min_puffs = min(b[k], puffs);
                max_pig_meso = max(max_pig_meso, min(c[k], min_puffs) + d[k]);
            }
        }
    }

    cout << max_pig_meso << endl;

    return 0;
}