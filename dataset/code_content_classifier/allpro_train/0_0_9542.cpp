#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<pair<long long, long long>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<long long> lucky_numbers;
    for (int i = 0; i < n; i++) {
        if (segments[i].first <= 4 && segments[i].second >= 7) {
            lucky_numbers.push_back(4);
            lucky_numbers.push_back(7);
        }
    }

    sort(lucky_numbers.begin(), lucky_numbers.end());

    long long ans = 0;
    for (int i = 0; i < lucky_numbers.size(); i++) {
        long long count = 0;
        long long moves_left = k;
        for (int j = i; j < lucky_numbers.size(); j++) {
            long long diff = lucky_numbers[j] - lucky_numbers[i];
            if (moves_left >= diff) {
                count++;
                moves_left -= diff;
            } else {
                break;
            }
        }
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}