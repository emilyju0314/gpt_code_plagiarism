#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int m, k, n, s;
    cin >> m >> k >> n >> s;

    vector<int> flowers(m);
    for (int i = 0; i < m; i++) {
        cin >> flowers[i];
    }

    vector<int> types(s);
    unordered_map<int, int> required;
    for (int i = 0; i < s; i++) {
        cin >> types[i];
        required[types[i]]++;
    }

    vector<int> positionsToRemove;
    int count = 0;
    unordered_map<int, int> seenTypes;
    for (int i = 0; i < m; i++) {
        seenTypes[flowers[i]]++;
        if (required.find(flowers[i]) != required.end() && seenTypes[flowers[i]] <= required[flowers[i]]) {
            count++;
            if (count == k) {
                for (int j = i - k + 1; j <= i; j++) {
                    positionsToRemove.push_back(j + 1);
                }
                count = 0;
            }
        }
    }

    if (positionsToRemove.size() < n * k) {
        cout << -1;
    } else {
        cout << positionsToRemove.size() - n * k << endl;
        for (int i = n * k; i < positionsToRemove.size(); i++) {
            cout << positionsToRemove[i] << " ";
        }
    }

    return 0;
}