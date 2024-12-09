#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> initialOrder(n);
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        cin >> initialOrder[i];
        index[initialOrder[i]] = i;
    }

    vector<int> plannedOrder(m);
    for (int i = 0; i < m; i++) {
        cin >> plannedOrder[i];
    }

    int gestures = 0;
    int currentScreen = 0;
    for (int i = 0; i < m; i++) {
        int appIndex = index[plannedOrder[i]];
        gestures += appIndex / k + 1;
        if (appIndex != currentScreen) {
            int temp = initialOrder[appIndex];
            initialOrder[appIndex] = initialOrder[appIndex-1];
            initialOrder[appIndex-1] = temp;
            index[temp] = appIndex - 1;
            index[initialOrder[appIndex]] = appIndex;
        }
        currentScreen = appIndex / k * k;
    }

    cout << gestures << endl;

    return 0;
}