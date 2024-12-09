#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    string number;
    unordered_map<char, pair<int, int>> keyMap = {
        {'1', {0, 0}}, {'2', {0, 1}}, {'3', {0, 2}},
        {'4', {1, 0}}, {'5', {1, 1}}, {'6', {1, 2}},
        {'7', {2, 0}}, {'8', {2, 1}}, {'9', {2, 2}},
        {'0', {2, 0}}
    };

    cin >> n >> number;

    vector<pair<int, int>> fingerMovements;

    for (int i = 0; i < n; i++) {
        fingerMovements.push_back(keyMap[number[i]]);
    }

    bool sameFingerMovements = true;

    for (int i = 1; i < n; i++) {
        if (fingerMovements[i] == fingerMovements[i-1]) {
            sameFingerMovements = false;
            break;
        }
    }

    if (sameFingerMovements) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}