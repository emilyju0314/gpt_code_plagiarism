#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    unordered_map<pair<int, int>, int> vectors_count;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            vectors_count[{dx, dy}]++;
        }
    }

    long long c = 0;
    for(auto& pair : vectors_count) {
        c += (long long)pair.second * (pair.second - 1) / 2;
    }

    cout << c << endl;

    return 0;
}