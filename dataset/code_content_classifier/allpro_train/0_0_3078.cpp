#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> guests(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        guests[i] = {a, b};
    }

    vector<pair<int, int>> food(n);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            food[i] = {1, 2};
        } else {
            food[i] = {2, 1};
        }
    }

    for (int i = 0; i < n; i++) {
        cout << food[i].first << " " << food[i].second << endl;
    }

    return 0;
}