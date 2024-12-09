#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(n);
    map<int, int> inMaintenance;
    vector<int> trainStatus(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            trainStatus[k] = x[k];
            inMaintenance[y[k]]++;
        } else {
            inMaintenance[y[k]]--;
            if (inMaintenance[y[k]] == 0) {
                inMaintenance.erase(y[k]);
            }
        }

        int totalMaintenance = 0;
        for (auto it = inMaintenance.begin(); it != inMaintenance.end(); it++) {
            totalMaintenance += it->second;
        }

        cout << totalMaintenance << endl;
    }

    return 0;
}