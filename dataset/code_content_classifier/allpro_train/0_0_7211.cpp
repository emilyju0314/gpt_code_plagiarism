#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> stops(n);
    for (int i = 0; i < n; i++) {
        cin >> stops[i];
    }

    vector<int> inspections(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> inspections[i];
    }

    double max_profit = 0.0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        double profit = max(stops[b-1] - stops[a-1] - c, 0) - (stops[b-1] - stops[a-1]) * (inspections[a-1] / 100.0);
        max_profit += profit;
    }

    cout << fixed << setprecision(9) << max_profit << endl;

    return 0;
}