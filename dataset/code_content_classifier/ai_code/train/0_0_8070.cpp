#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> projects; // pair of completed projects and index
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        projects.push_back(make_pair(a, i));
    }

    sort(projects.begin(), projects.end(), compare);

    vector<int> b(n);
    int remaining = k;
    for (int i = 0; i < n; i++) {
        int num = min(projects[i].first, remaining);
        b[projects[i].second] = num;
        remaining -= num;
    }

    for (int i : b) {
        cout << i << " ";
    }

    return 0;
}