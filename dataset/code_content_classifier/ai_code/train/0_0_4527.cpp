#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int la, lb;
    cin >> la >> lb;

    vector<int> a(la);
    vector<int> b(lb);

    unordered_map<int, int> indexMap;

    for (int i = 0; i < la; i++) {
        cin >> a[i];
        indexMap[a[i]] = i;
    }

    for (int i = 0; i < lb; i++) {
        cin >> b[i];
    }

    int maxLength = 0;
    int currentLength = 0;
    int currentStart = 0;

    for (int i = 0; i < lb; i++) {
        if (indexMap.find(b[i]) != indexMap.end()) {
            if (indexMap[b[i]] < currentStart) {
                currentLength = 1;
                currentStart = indexMap[b[i]];
            } else {
                currentLength = indexMap[b[i]] - currentStart + 1;
                currentStart = indexMap[b[i]];
            }
            maxLength = max(maxLength, currentLength);
        }
    }

    cout << maxLength << endl;

    return 0;
}