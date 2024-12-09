#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> shelves(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int num_items;
        cin >> num_items;
        shelves[i].resize(num_items);
        for (int j = 0; j < num_items; j++) {
            cin >> shelves[i][j];
        }
    }

    int total_damage = 0;
    for (int i = 0; i <= m; i++) {
        int max_damage = 0;
        for (int j = 0; j <= i && j < n; j++) {
            int damage = 0;
            for (int k = 0; k <= shelves[j].size() && k <= i - j; k++) {
                int temp_damage = 0;
                for (int l = 0; l < k; l++) {
                    temp_damage += shelves[j][l];
                }
                for (int l = 0; l < i - j - k; l++) {
                    temp_damage += shelves[j][shelves[j].size() - 1 - l];
                }
                damage = max(damage, temp_damage);
            }
            max_damage = max(max_damage, damage);
        }
        total_damage += max_damage;
    }

    cout << total_damage << endl;

    return 0;
}