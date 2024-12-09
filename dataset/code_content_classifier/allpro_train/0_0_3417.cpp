#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        monsters[i] = {r, c};
    }

    int count = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n - k + 1; i++) {
            for (int j = 1; j <= n - k + 1; j++) {
                int monsterCount = 0;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        for (auto monster : monsters) {
                            if (monster.first == x && monster.second == y) {
                                monsterCount++;
                            }
                        }
                    }
                }
                if (monsterCount == k) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}