#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> trips(n);
    for (int i = 0; i < n; i++) {
        cin >> trips[i];
    }

    int total = 0;
    int last90 = 0;
    int lastDay = 0;

    for (int i = 0; i < n; i++) {
        int diff90 = trips[i] - last90;
        int diffDay = trips[i] - lastDay;

        int cost = 20;
        if (diff90 <= 90) {
            cost = min(cost, 50);
        }
        if (diffDay <= 1440) {
            cost = min(cost, 120);
        }

        cout << cost - total << endl;
        total = cost;

        if (diff90 > 90) {
            last90 = trips[i];
        }
        if (diffDay > 1440) {
            lastDay = trips[i];
        }
    }

    return 0;
}