#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(pair<int,int> &a, pair<int,int> &b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int,int>> order;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        order.push_back({a[i], i+1});
    }

    sort(order.begin(), order.end(), comparator);

    int shots = 0;
    for (int i = 0; i < n; i++) {
        shots += a[order[i].second - 1] * i + 1;
    }

    cout << shots << endl;

    for (int i = 0; i < n; i++) {
        cout << order[i].second << " ";
    }

    return 0;
}