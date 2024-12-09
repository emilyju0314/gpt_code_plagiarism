#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments; // {left coordinate, right coordinate}
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back(make_pair(l, r));

        vector<int> ends = {l, r};

        // Record the connected component count before adding the current segment
        int prev_components = 0;
        for (int j = 0; j < segments.size(); j++) {
            if (segments[j].first <= r && segments[j].second >= l) {
                prev_components++;
            }
        }

        // Update the connected component count after adding the current segment
        answer.push_back(prev_components + 2 - ends.size());
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}