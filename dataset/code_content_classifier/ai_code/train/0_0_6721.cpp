#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int>> seals;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        seals.push_back({x, y});
        seals.push_back({y, x});
    }

    int max_area = 0;

    for(auto seal1 : seals) {
        for(auto seal2 : seals) {
            if(seal1.first + seal2.first <= a && max(seal1.second, seal2.second) <= b) {
                int area = seal1.first * seal1.second + seal2.first * seal2.second;
                max_area = max(max_area, area);
            }
        }
    }

    cout << max_area << endl;

    return 0;
}