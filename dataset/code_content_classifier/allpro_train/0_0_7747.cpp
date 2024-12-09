#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> neighbors(n+1);
    unordered_map<int, int> in_front, behind;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        neighbors[i] = {a, b};
        in_front[a] = i;
        behind[b] = i;
    }

    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (in_front[i] == 0) {
            start = i;
            break;
        }
    }

    while (start != 0) {
        cout << start << " ";
        start = neighbors[start].second;
    }

    return 0;
}