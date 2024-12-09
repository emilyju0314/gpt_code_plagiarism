#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> alpinists(n);
    for (int i = 0; i < n; i++) {
        cin >> alpinists[i].first >> alpinists[i].second;
    }

    sort(alpinists.begin(), alpinists.end());

    int max_count = 0;
    long long current_difficulty = d;
    for (int i = 0; i < n; i++) {
        if (alpinists[i].first >= current_difficulty) {
            current_difficulty = max(current_difficulty, (long long)alpinists[i].second);
            max_count++;
        }
    }

    cout << max_count << endl;

    return 0;
}