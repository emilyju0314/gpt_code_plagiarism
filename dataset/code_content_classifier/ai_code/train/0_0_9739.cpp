#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);
    unordered_map<int, int> cardMap;

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        cardMap[cards[i]] = i + 1;
    }

    vector<int> target(k);
    for (int i = 0; i < k; i++) {
        cin >> target[i];
    }

    long long sausages = 0;

    int maxIdx = 0;
    for (int i = 0; i < k - 1; i++) {
        int curIdx = cardMap[target[i]];
        int nextIdx = cardMap[target[i + 1]];

        if (curIdx > nextIdx) {
            maxIdx = max(maxIdx, curIdx);
        } else {
            sausages += maxIdx;
            maxIdx = 0;
        }
    }

    sausages += maxIdx;

    cout << sausages << endl;

    return 0;
}