#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> houses;
    for (int i = 0; i < n; i++) {
        int x, a;
        cin >> x >> a;
        houses.push_back(make_pair(x, a));
    }

    int possible_positions = 2; // start with 2 possible positions (left and right of all existing houses)
    for (int i = 0; i < houses.size(); i++) {
        int x = houses[i].first;
        int a = houses[i].second;

        int left_limit = x - a / 2 - t / 2; // calculate left limit based on existing house i
        int right_limit = x + a / 2 + t / 2; // calculate right limit based on existing house i

        if (i > 0) {
            int prev_x = houses[i - 1].first;
            int prev_a = houses[i - 1].second;
            left_limit = max(left_limit, prev_x + prev_a / 2 + t / 2); // update left limit if necessary
        }

        if (i < houses.size() - 1) {
            int next_x = houses[i + 1].first;
            int next_a = houses[i + 1].second;
            right_limit = min(right_limit, next_x - next_a / 2 - t / 2); // update right limit if necessary
        }

        possible_positions += max(0, right_limit - left_limit); // update possible positions
    }

    cout << possible_positions << endl;

    return 0;
}