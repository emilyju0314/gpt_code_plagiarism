#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    int count = 2; // Starting with 2 trees for sure
    for (int i = 1; i < n - 1; i++) {
        if (trees[i - 1].first < trees[i].first - trees[i].second) {
            count++;
        } else if (trees[i].first + trees[i].second < trees[i + 1].first) {
            count++;
            trees[i].first += trees[i].second;
        }
    }

    cout << count << endl;

    return 0;
}