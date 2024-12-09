#include <iostream>
#include <vector>

using namespace std;

struct Pony {
    int s, m, r;
};

int main() {
    int n;
    cin >> n;

    vector<Pony> ponies(n);
    for (int i = 0; i < n; i++) {
        cin >> ponies[i].s >> ponies[i].m >> ponies[i].r;
    }

    int m;
    cin >> m;

    long long totalMana = 0;
    long long time = 0;

    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;

        for (int j = 0; j < n; j++) {
            if (j >= l - 1 && j <= r - 1) {
                long long manaAbsorbed = min((long long)ponies[j].m - ponies[j].s, time * ponies[j].r);
                totalMana += manaAbsorbed;
                ponies[j].s += manaAbsorbed;
            }
        }

        cout << totalMana << endl;

        time = t;
    }

    return 0;
}