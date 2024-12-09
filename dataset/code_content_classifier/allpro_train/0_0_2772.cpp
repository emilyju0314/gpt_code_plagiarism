#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<pair<int, int>, pair<int, int>> memo;

pair<int, int> calculateOutcome(vector<int>& piles, int a, int b) {
    if (memo.count({a, b})) {
        return memo[{a, b}];
    }

    int total = 0;
    int winsAlice = 0;
    int winsBob = 0;

    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] < a) continue;

        vector<int> newPiles = piles;
        newPiles[i] -= a;

        pair<int, int> next = calculateOutcome(newPiles, b, a);

        total++;
        
        if (next.first == 0) {
            winsAlice++;
        } else {
            winsBob++;
        }
    }

    if (total == 0 || winsAlice == 0) {
        memo[{a, b}] = {1, 0};
        return {1, 0};
    } else if (winsBob == 0) {
        memo[{a, b}] = {0, 1};
        return {0, 1};
    } else {
        memo[{a, b}] = {1, 1};
        return {1, 1};
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    pair<int, int> result = calculateOutcome(piles, 1, 1);

    int w_a = result.first;
    int w_b = result.second;
    int w_f = result.first + result.second;
    int w_s = n * n;

    cout << w_a << " " << w_b << " " << w_f << " " << w_s << endl;

    return 0;
}