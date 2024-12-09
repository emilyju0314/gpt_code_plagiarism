#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkValidOrder(vector<pair<int, int>>& skyscrapers) {
    for (int i = 2; i < skyscrapers.size(); i++) {
        int x1 = skyscrapers[i-2].first;
        int y1 = skyscrapers[i-2].second;
        int x2 = skyscrapers[i-1].first;
        int y2 = skyscrapers[i-1].second;
        int x3 = skyscrapers[i].first;
        int y3 = skyscrapers[i].second;

        if ((x1 - x2) * (y2 - y3) != (y1 - y2) * (x2 - x3)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> skyscrapers(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        skyscrapers[i] = {x, y};
    }

    sort(skyscrapers.begin(), skyscrapers.end());

    if (!checkValidOrder(skyscrapers)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}