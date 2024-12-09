#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> blackTokens;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        blackTokens.insert({x, y});
    }

    int validWhiteTokenCount = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            set<pair<int, int>> whiteTokens;
            bool valid = true;
            for (auto token : blackTokens) {
                int x = token.first + dx;
                int y = token.second + dy;
                if (whiteTokens.count({x, y}) || blackTokens.count({x, y})) {
                    valid = false;
                    break;
                } else {
                    whiteTokens.insert({x, y});
                }
            }
            if (valid) {
                validWhiteTokenCount += whiteTokens.size();
            }
        }
    }

    cout << validWhiteTokenCount << endl;

    return 0;
}