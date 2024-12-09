#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minSubscriptions(vector<int>& shows, int k, int d) {
    unordered_set<int> uniqueShows;
    vector<int> freq(k + 1, 0);
    int count = 0, ans = d;

    for (int i = 0; i < d; i++) {
        if (freq[shows[i]] == 0) {
            count++;
        }
        freq[shows[i]]++;
        uniqueShows.insert(shows[i]);
    }

    ans = min(ans, count);

    for (int i = d; i < shows.size(); i++) {
        freq[shows[i-d]]--;
        if (freq[shows[i-d]] == 0) {
            count--;
        }

        if (freq[shows[i]] == 0) {
            count++;
        }
        freq[shows[i]]++;

        uniqueShows.insert(shows[i]);

        ans = min(ans, count);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> shows(n);
        for (int i = 0; i < n; i++) {
            cin >> shows[i];
        }

        int result = minSubscriptions(shows, k, d);
        cout << result << endl;
    }

    return 0;
}