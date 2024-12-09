#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> blocks(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        blocks[i] = make_pair(a, b);
    }

    sort(blocks.begin(), blocks.end(), compare);

    vector<int> dp(N);
    int max_height = 0;

    for(int i = 0; i < N; i++) {
        dp[i] = blocks[i].second;

        for(int j = 0; j < i; j++) {
            if(blocks[i].second >= blocks[j].second) {
                dp[i] = max(dp[i], dp[j] + blocks[i].second);
            }
        }

        max_height = max(max_height, dp[i]);
    }

    cout << max_height << endl;

    return 0;
}