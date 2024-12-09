#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].first >> projects[i].second;
    }

    sort(projects.begin(), projects.end());

    for (int i = 0; i < n; i++) {
        if (r < projects[i].first) {
            cout << "NO" << endl;
            return 0;
        }
        r += projects[i].second;
    }

    cout << "YES" << endl;

    return 0;
}