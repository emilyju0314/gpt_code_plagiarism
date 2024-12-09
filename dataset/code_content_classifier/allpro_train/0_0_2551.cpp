#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int maxMoney = 0;
    for (int i = 0; i <= min(s / e, n); i++) {
        if (i * e > s) {
            break;
        }
        int remainingEnergy = s - i * e;
        int money = i;
        for (int j = 0; j < m; j++) {
            if (j * e <= remainingEnergy && a[i] == b[j]) {
                money++;
                remainingEnergy -= j * e;
            }
        }
        maxMoney = max(maxMoney, money);
    }

    cout << maxMoney << endl;

    return 0;
}