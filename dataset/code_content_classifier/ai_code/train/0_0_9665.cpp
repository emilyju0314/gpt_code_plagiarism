#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }

    int t = 0;
    vector<int> spells;

    for (int i = 1; i < n - 1; i++) {
        while (health[i] > 0) {
            spells.push_back(i);
            t++;
            health[i] -= a;

            if (i + 1 < n) {
                health[i + 1] -= b;
            }
            if (i - 1 > 0) {
                health[i - 1] -= b;
            }
        }
    }

    cout << t << endl;
    for (int i = 0; i < spells.size(); i++) {
        cout << spells[i] << " ";
    }

    return 0;
}