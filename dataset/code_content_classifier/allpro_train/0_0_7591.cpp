#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w, m;
    cin >> n >> w >> m;

    vector<vector<double>> cups(m, vector<double>(n, 0.0));

    double total_milk = n * w;
    double amount_per_cup = total_milk / m;

    if (amount_per_cup > 2 * w) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        for (int i = 0; i < m; i++) {
            double remaining_milk = amount_per_cup;
            for (int j = 0; j < n; j++) {
                double pour_amount = min(remaining_milk, w);
                cups[i][j] = pour_amount;
                remaining_milk -= pour_amount;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cups[i][j] > 0) {
                    cout << j + 1 << " " << fixed << setprecision(6) << cups[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}