#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> p(4);
    vector<int> t(4);

    for (int i = 0; i < 4; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> t[i];
    }

    int min_cost = INT_MAX;

    for (int i = 0; i < (1 << 4); i++) {
        int total_cups = 0;
        int cost = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                int num_packages = (N + t[j] - 1) / t[j];
                total_cups += num_packages * t[j];
                cost += num_packages * p[j];
            }
        }
        if (total_cups >= N) {
            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << endl;

    return 0;
}