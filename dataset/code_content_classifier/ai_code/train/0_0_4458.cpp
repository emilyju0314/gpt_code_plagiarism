#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> happyBoys(n, false);
    vector<bool> happyGirls(m, false);

    int b;
    cin >> b;
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        happyBoys[x] = true;
    }

    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
        int y;
        cin >> y;
        happyGirls[y] = true;
    }

    bool canMakeHappy = false;
    for (int i = 0; i < max(n, m); i++) {
        if (happyBoys[i % n] || happyGirls[i % m]) {
            happyBoys[i % n] = true;
            happyGirls[i % m] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!happyBoys[i]) {
            canMakeHappy = false;
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!happyGirls[i]) {
            canMakeHappy = false;
            break;
        }
    }

    if (canMakeHappy) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}