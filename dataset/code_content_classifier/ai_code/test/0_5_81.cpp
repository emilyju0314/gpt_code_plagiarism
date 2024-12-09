#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> alpinists;

    for (int i = 0; i < n; i++) {
        int s, a;
        cin >> s >> a;
        alpinists.push_back(make_pair(s, a));
    }

    sort(alpinists.begin(), alpinists.end()); // Sort alpinists based on skill level

    int maxNeatness = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (alpinists[i].first <= d) { // Check if alpinist can climb the mountain
            if (alpinists[i].second >= maxNeatness) {
                maxNeatness = alpinists[i].second;
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}