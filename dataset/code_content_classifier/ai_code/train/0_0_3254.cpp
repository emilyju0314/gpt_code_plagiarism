#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    long long m;
    cin >> q >> m;

    long long j = 0;
    vector<pair<long long, long long>> spells;

    for(int i = 0; i < q; i++) {
        int k;
        long long a, b;
        cin >> k >> a >> b;

        if(k == 1) {
            long long x = (a + j) % 106 + 1;
            long long y = (b + j) % 106 + 1;
            spells.push_back({x, y});
        } else {
            long long t = (a + j) % 106 + 1;
            long long h = (b + j) % 106 + 1;

            bool canWin = false;
            for(auto spell : spells) {
                long long damage = spell.first;
                long long manaCost = spell.second;
                if(damage * t >= h && manaCost * t <= m) {
                    canWin = true;
                    break;
                }
            }

            if(canWin) {
                cout << "YES" << endl;
                j = 0;
            } else {
                cout << "NO" << endl;
                j = 1;
            }
        }
    }

    return 0;
}