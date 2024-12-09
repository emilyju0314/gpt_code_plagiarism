#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> facilities(N);
    for(int i = 0; i < N; i++) {
        cin >> facilities[i].first >> facilities[i].second;
    }

    // Sort the facilities based on x coordinate
    sort(facilities.begin(), facilities.end());

    int max_dist = 0;
    for(int i = 0; i < N - 1; i++) {
        max_dist = max(max_dist, abs(facilities[i].first - facilities[i+1].first));
    }

    // Sort the facilities based on y coordinate
    sort(facilities.begin(), facilities.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });

    for(int i = 0; i < N - 1; i++) {
        max_dist = max(max_dist, abs(facilities[i].second - facilities[i+1].second));
    }

    cout << max_dist << endl;

    return 0;
}