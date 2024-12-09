#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> initialMoney(n);
    for(int i = 0; i < n; i++) {
        cin >> initialMoney[i];
    }

    vector<pair<int, int>> recommendations;
    vector<double> probabilities;
    for(int i = 0; i < q; i++) {
        int l, r;
        double p;
        cin >> l >> r >> p;
        recommendations.push_back({l, r});
        probabilities.push_back(p);
    }

    vector<double> maxMoney(n);
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < n; j++) {
            if(j >= recommendations[i].first - 1 && j <= recommendations[i].second - 1) {
                maxMoney[j] = max(maxMoney[j], probabilities[i]);
            }
        }
    }

    for(int i = 0; i < q; i++) {
        for(int j = 0; j < n; j++) {
            if(j >= recommendations[i].first - 1 && j <= recommendations[i].second - 1) {
                maxMoney[j] = max(maxMoney[j], probabilities[i]);
            }
        }
    }

    double expectedGoodness = 0.0;
    for(int i = 0; i < n; i++) {
        expectedGoodness += (1 - maxMoney[i]) * initialMoney[i] + maxMoney[i];
    }

    cout << fixed << setprecision(9) << expectedGoodness << endl;

    return 0;
}