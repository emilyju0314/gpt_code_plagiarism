#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    vector<int> y(n);
    vector<int> isMaintenance(n, 0); // 0 = not in maintenance, 1 = in maintenance
    map<int, int> modelDaysLeft;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            modelDaysLeft[k] = x[k]; // Train k added, set days left to x[k]
        } else {
            if (modelDaysLeft.count(k) && modelDaysLeft[k] > 0) {
                modelDaysLeft[k] = 0; // Train k removed, set days left to 0
            }
        }

        // Check and update maintenance status
        for (auto& p : modelDaysLeft) {
            if (p.second > 0) {
                p.second--; // Decrease the days left to work
                if (p.second == 0) {
                    p.second = -y[p.first]; // Set days left to maintenance
                }
                if (p.second == 0) {
                    isMaintenance[p.first] = 1; // Set maintenance status to true
                }
            } else if (p.second < 0) {
                p.second++; // Increase the days left to maintenance
                if (p.second == 0) {
                    isMaintenance[p.first] = 0; // Set maintenance status to false
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << isMaintenance[i] << endl;
    }

    return 0;
}