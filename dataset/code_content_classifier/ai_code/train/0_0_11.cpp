#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string lamps;
    cin >> lamps;

    vector<vector<int>> subsets(k);
    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for(int j = 0; j < c; j++) {
            int x;
            cin >> x;
            subsets[i].push_back(x);
        }
    }

    vector<int> prefix_sum(n+1);
    for(int i = 0; i < k; i++) {
        int sum = 0;
        for(auto it : subsets[i]) {
            sum += lamps[it-1] - '0';
        }
        prefix_sum[subsets[i].size()] = max(prefix_sum[subsets[i].size()], sum);
    }

    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = max(prefix_sum[i], prefix_sum[i-1]);
    }

    for(int i = 1; i <= n; i++) {
        cout << i - prefix_sum[i] << "\n";
    }

    return 0;
}