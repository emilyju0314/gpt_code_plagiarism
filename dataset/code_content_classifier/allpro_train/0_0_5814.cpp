#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> spells;
    for(int i = 0; i < n; i++) {
        int L, R;
        cin >> L >> R;
        spells.push_back({L, R});
    }

    vector<int> count(m + 1, 0);
    for(auto spell : spells) {
        count[spell.first]++;
        count[spell.second + 1]--;
    }

    for(int i = 1; i <= m; i++) {
        count[i] += count[i - 1];
    }

    int happyChildren = 0;
    for(int i = 1; i <= m; i++) {
        if(count[i] <= k) {
            happyChildren++;
        }
    }

    cout << happyChildren << endl;

    return 0;
}