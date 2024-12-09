#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int a, x;
    cin >> a;
    vector<int> masha(a);
    for (int i = 0; i < a; i++) {
        cin >> x;
        masha[x - 1] = 1;
    }

    int b, y;
    cin >> b;
    vector<int> arkady(b);
    for (int i = 0; i < b; i++) {
        cin >> y;
        arkady[y - 1] = 1;
    }

    vector<int> both;
    vector<int> onlyMasha;
    vector<int> onlyArkady;
    for (int i = 0; i < n; i++) {
        if (masha[i] == 1 && arkady[i] == 1) {
            both.push_back(cost[i]);
        } else if (masha[i] == 1) {
            onlyMasha.push_back(cost[i]);
        } else if (arkady[i] == 1) {
            onlyArkady.push_back(cost[i]);
        }
    }

    if (both.size() + max((int)onlyMasha.size(), k) + max((int)onlyArkady.size(), k) < m) {
        cout << "-1" << endl;
        return 0;
    }

    sort(both.begin(), both.end());
    sort(onlyMasha.begin(), onlyMasha.end());
    sort(onlyArkady.begin(), onlyArkady.end());

    int minCost = 0;
    int count = 0;

    while (!both.empty() && count < m) {
        minCost += both[0];
        both.erase(both.begin());
        count++;
    }

    while (count < m) {
        if (onlyMasha.empty() || onlyArkady.empty()) {
            minCost += both[0];
            both.erase(both.begin());
        } else if (onlyMasha[0] + onlyArkady[0] < both[0]) {
            minCost += onlyMasha[0] + onlyArkady[0];
            onlyMasha.erase(onlyMasha.begin());
            onlyArkady.erase(onlyArkady.begin());
        } else {
            minCost += both[0];
            both.erase(both.begin());
        }
        count++;
    }

    cout << minCost << endl;

    return 0;
}