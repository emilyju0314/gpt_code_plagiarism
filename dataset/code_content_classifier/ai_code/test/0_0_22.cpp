#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> time(n, -1);
    int maintenanceCount = 0;

    for(int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if(op == 1) {
            time[k] = x[k];
        } else {
            if(time[k] != -1) {
                time[k] = -1;
            }
        }

        maintenanceCount = 0;
        for(int j = 0; j < n; j++) {
            if(time[j] > 0) {
                maintenanceCount++;
                time[j]--;
                if(time[j] == 0) {
                    time[j] = y[j];
                }
            }
        }

        cout << maintenanceCount << endl;
    }

    return 0;
}