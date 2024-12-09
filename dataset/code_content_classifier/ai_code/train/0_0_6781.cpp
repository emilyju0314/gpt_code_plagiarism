#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    vector<pair<int, int>> possibleOutcomes;

    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i > j) {
                possibleOutcomes.push_back({i, j});
            }
        }
    }

    cout << possibleOutcomes.size() << endl;

    for (auto outcome : possibleOutcomes) {
        cout << outcome.first << " " << outcome.second << endl;
    }

    return 0;
}