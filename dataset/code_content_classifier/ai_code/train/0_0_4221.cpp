#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Monster {
    int x;
    int h;
};

int main() {
    int n, d, a;
    cin >> n >> d >> a;

    vector<Monster> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i].x >> monsters[i].h;
    }

    sort(monsters.begin(), monsters.end(), [](const Monster &m1, const Monster &m2) {
        return m1.x < m2.x;
    });

    long long bombs = 0;
    long long totalHealth = 0;

    vector<long long> damage(n, 0);

    for (int i = 0; i < n; i++) {
        totalHealth += monsters[i].h;

        if (totalHealth <= 0) {
            continue;
        }

        long long remainingDamage = max(0LL, monsters[i].h - damage[i]);
        long long numBombs = (remainingDamage + a - 1) / a;

        bombs += numBombs;

        totalHealth -= numBombs * a;
        damage[i] += numBombs * a;

        int j = lower_bound(monsters.begin(), monsters.end(), monsters[i].x + 2 * d, [](const Monster &m, int x) {
            return m.x < x;
        }) - monsters.begin();

        damage[j] += numBombs * a;
    }

    cout << bombs << endl;

    return 0;
}