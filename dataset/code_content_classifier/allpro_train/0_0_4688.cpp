#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> shows(n);
        for (int j = 0; j < n; j++) {
            cin >> shows[j];
        }

        unordered_map<int, int> freq;
        int unique_shows = 0;
        int ans = d;

        for (int j = 0; j < d; j++) {
            if (freq[shows[j]] == 0) {
                unique_shows++;
            }
            freq[shows[j]]++;
        }

        ans = unique_shows;

        for (int j = d; j < n; j++) {
            if (freq[shows[j-d]] == 1) {
                unique_shows--;
            }
            freq[shows[j-d]]--;

            if (freq[shows[j]] == 0) {
                unique_shows++;
            }
            freq[shows[j]]++;

            ans = min(ans, unique_shows);
        }

        cout << ans << endl;
    }

    return 0;
}