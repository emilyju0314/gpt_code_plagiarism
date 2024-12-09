#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> remembered(n);
    unordered_map<int, pair<int, int>> info;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        remembered[i] = {a, b};
        info[a] = {b, i + 1};
    }

    int start = remembered[0].first;
    int next = remembered[start - 1].first;

    cout << start << " ";
    while (next != start) {
        cout << next << " ";
        next = info[next].first;
    }

    return 0;
}