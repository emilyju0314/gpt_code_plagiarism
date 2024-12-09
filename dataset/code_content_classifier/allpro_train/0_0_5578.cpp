#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> capacities(n);
    for (int i = 0; i < n; i++) {
        cin >> capacities[i];
    }

    cin >> m;

    vector<long long> water(n, 0);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;
            water[p - 1] += x;
        } else {
            int k;
            cin >> k;
            long long total = water[k - 1];

            for (int j = k - 2; j >= 0; j--) {
                total += water[j];
                if (total > capacities[j]) {
                    water[j] = capacities[j];
                    total = total - capacities[j];
                } else {
                    water[j] = total;
                    total = 0;
                }
            }

            cout << total << endl;
        }
    }

    return 0;
}