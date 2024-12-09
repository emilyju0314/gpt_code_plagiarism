#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int R = -1; // Initial value of R

int rotate(int element) {
    element = (element + R) % n;

    if (element == 0) {
        element = n;
    }

    return element;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> machines(m);
    for (int i = 0; i < m; i++) {
        cin >> machines[i].first >> machines[i].second;
    }

    for (int query = 1; query <= q; query++) {
        int ni, mi;
        cin >> ni >> mi;

        vector<int> favorite(ni);
        for (int i = 0; i < ni; i++) {
            cin >> favorite[i];
        }

        vector<pair<int, int>> radewooshMachines(mi);
        for (int i = 0; i < mi; i++) {
            cin >> radewooshMachines[i].first >> radewooshMachines[i].second;
        }

        unordered_map<int, int> elementToIndex;
        for (int i = 0; i < ni; i++) {
            elementToIndex[favorite[i]] = i;
        }

        bool success = true;
        for (int i = 0; i < mi; i++) {
            int ai = rotate(radewooshMachines[i].first);
            int bi = rotate(radewooshMachines[i].second);

            if (elementToIndex.find(ai) != elementToIndex.end() && elementToIndex.find(bi) != elementToIndex.end()) {
                int aiIndex = elementToIndex[ai];
                int biIndex = elementToIndex[bi];

                if (abs(aiIndex - biIndex) % ni == 1 || abs(aiIndex - biIndex) % ni == ni - 1) {
                    success = false;
                    break;
                }
            }
        }

        if (success) {
            cout << "YES" << endl;
            R = query - 1;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}