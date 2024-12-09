#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pairs(m);
    for(int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    int odd_permutations = 1;
    for(int i = 0; i < m; i++) {
        vector<bool> used(n + 1, false);
        used[pairs[i].second] = true;

        int empty_positions = n;
        for(int j = 0; j < m; j++) {
            if(j != i) {
                if(!used[pairs[j].second]) {
                    used[pairs[j].second] = true;
                    empty_positions--;
                }
            }
        }

        odd_permutations = (odd_permutations + (empty_positions % 2)) % 2;
        if(odd_permutations == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}