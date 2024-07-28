#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    vector<pair<int, int>> solutions;

    while (cin >> k) {
        for (int y = k + 1; y <= 2 * k; y++) {
            if ((k * y) % (y - k) == 0) {
                int x = (k * y) / (y - k);
                solutions.push_back({x, y});
            }
        }
    }

    cout << solutions.size() << endl;
    for (pair<int, int> solution : solutions) {
        cout << "1/" << k << " = 1/" << solution.first << " + 1/" << solution.second << endl;
    }

    return 0;
}
