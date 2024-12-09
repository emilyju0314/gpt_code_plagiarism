#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> devices(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        devices[i] = make_pair(a, b);
    }

    double time = 0.0;
    double max_time = 1e10; // set a large initial value
    
    while (true) {
        bool zero_power = false;

        for (int i = 0; i < n; i++) {
            if (devices[i].second <= 0) {
                zero_power = true;
                break;
            }
        }

        if (zero_power) {
            break;
        }

        double min_charge_time = 1e10; // set a large initial value
        
        for (int i = 0; i < n; i++) {
            if (devices[i].first > p) {
                min_charge_time = min(min_charge_time, (double)devices[i].second / (double)(devices[i].first - p));
            }
        }

        time += min_charge_time;
        
        for (int i = 0; i < n; i++) {
            devices[i].second -= min_charge_time * devices[i].first;
        }
    }

    cout << (max_time == 1e10 ? -1 : time) << endl;

    return 0;
}