#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<pair<int, int>> startScheme;
vector<pair<int, int>> endScheme;

void readInput() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        startScheme.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        endScheme.push_back(make_pair(x, y));
    }
}

int main() {
    readInput();

    unordered_map<int, int> startMap;
    unordered_map<int, int> endMap;

    for (int i = 0; i < n - 1; i++) {
        startMap[startScheme[i].first] = startScheme[i].second;
        startMap[startScheme[i].second] = startScheme[i].first;
    }

    for (int i = 0; i < n - 1; i++) {
        endMap[endScheme[i].first] = endScheme[i].second;
        endMap[endScheme[i].second] = endScheme[i].first;
    }

    vector<pair<int, int>> operations;
    for (int i = 0; i < n - 1; i++) {
        if (startScheme[i] != endScheme[i]) {
            int current = endScheme[i].first;
            while (endMap[current] != startScheme[i].second) {
                current = endMap[current];
            }
            operations.push_back(make_pair(startScheme[i].first, startScheme[i].second));
            operations.push_back(make_pair(current, endScheme[i].first));
            operations.push_back(make_pair(current, endScheme[i].second));
        }
    }

    if (operations.size() <= n - 2) {
        cout << operations.size() << endl;
        for (int i = 0; i < operations.size(); i++) {
            cout << operations[i].first << " " << operations[i].second << " " << operations[i+2].first << " " << operations[i+2].second << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}