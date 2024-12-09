#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<pair<int, int>> coins, diamonds;

    for (int i = 0; i < n; i++) {
        int beauty, cost;
        char type;
        cin >> beauty >> cost >> type;
        
        if (type == 'C') {
            if (cost <= c) {
                coins.push_back(make_pair(beauty, cost));
            }
        } else {
            if (cost <= d) {
                diamonds.push_back(make_pair(beauty, cost));
            }
        }
    }

    sort(coins.begin(), coins.end());
    sort(diamonds.begin(), diamonds.end());

    int maxBeauty = 0;

    // Find the maximum total beauty with 2 fountains
    if (!coins.empty() && coins.size() > 1) {
        maxBeauty = max(maxBeauty, coins[coins.size()-1].first + coins[coins.size()-2].first);
    }
    if (!diamonds.empty() && diamonds.size() > 1) {
        maxBeauty = max(maxBeauty, diamonds[diamonds.size()-1].first + diamonds[diamonds.size()-2].first);
    }

    // Find the maximum total beauty with 1 fountain from each type
    if (!coins.empty() && !diamonds.empty()) {
        maxBeauty = max(maxBeauty, coins[coins.size()-1].first + diamonds[diamonds.size()-1].first);
    }

    cout << maxBeauty << endl;

    return 0;
}