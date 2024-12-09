#include <iostream>
#include <vector>

using namespace std;

bool checkCrossProduct(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
    long long crossProduct = (p2.first - p1.first) * 1LL * (p3.second - p1.second) - (p2.second - p1.second) * 1LL * (p3.first - p1.first);
    return crossProduct == 0;
}

double calculateArea(const vector<pair<int, int>>& houses) {
    int count = 0;
    int total = 0;
    for (int x = -106; x <= 106; x++) {
        for (int y = -106; y <= 106; y++) {
            bool valid = true;
            for (int i = 1; i < houses.size(); i++) {
                if (checkCrossProduct(houses[0], {x, y}, houses[i])) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
            total++;
        }
    }
    return (double)count / total * 4 * 1e12;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<pair<int, int>> houses(n);
        for (int i = 0; i < n; i++) {
            cin >> houses[i].first >> houses[i].second;
        }

        double area = calculateArea(houses);
        cout << fixed << area << endl;
    }

    return 0;
}