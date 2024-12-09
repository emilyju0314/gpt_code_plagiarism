#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> stops(n);
    for(int i = 0; i < n; i++) {
        cin >> stops[i];
    }

    vector<int> inspection_rate(n-1);
    for(int i = 0; i < n-1; i++) {
        cin >> inspection_rate[i];
    }

    double total_profit = 0;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        double ticket_cost = stops[b-1] - stops[a-1];
        double passenger_profit = ticket_cost / 2.0;

        for(int j = a-1; j < b-1; j++) {
            passenger_profit -= (double)c / 100 * inspection_rate[j] * ticket_cost;
        }

        total_profit += passenger_profit;
    }

    cout << fixed << setprecision(9) << total_profit << endl;

    return 0;
}