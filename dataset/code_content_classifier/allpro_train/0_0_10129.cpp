#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, double>> cards;
        for (int i = 0; i < m; i++) {
            int a;
            double p;
            cin >> a >> p;
            cards.push_back(make_pair(a, p));
        }

        sort(cards.begin(), cards.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
            return a.second > b.second;
        });

        double sum_p = 0.0;
        for (int i = 0; i < m; i++) {
            sum_p += cards[i].second;
            if (sum_p >= 1.0) {
                cout << "YES" << endl;
                break;
            }
        }
    }

    return 0;
}