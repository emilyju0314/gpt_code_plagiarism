#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> hills(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> hills[i];
    }

    vector<vector<pair<int, int>>> cats(n); // cats[i] stores the cats at hill i with their finishing time
    for (int i = 0; i < m; i++) {
        int hi, ti;
        cin >> hi >> ti;
        cats[hi - 1].push_back({ti, 0});
    }

    for (int i = 0; i < n; i++) {
        sort(cats[i].begin(), cats[i].end());
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> feeders;
    
    long long sum_waiting_time = 0;
    int cat_index = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < cats[i].size(); j++) {
            while (!feeders.empty() && feeders.top().first <= cats[i][j].first) {
                pair<long long, int> top = feeders.top();
                feeders.pop();
                sum_waiting_time += top.first - cats[i][j].first;
                cats[i][j].second = top.first;
            }

            if (feeders.size() < p) {
                feeders.push({cats[i][j].second + hills[i], cat_index});
                cat_index++;
            } else if (!feeders.empty() && feeders.top().first > cats[i][j].first) {
                pair<long long, int> top = feeders.top();
                feeders.pop();
                sum_waiting_time += top.first - cats[i][j].first;
                cats[i][j].second = top.first;
                feeders.push({top.first + hills[i], top.second});
            }
        }
    }

    cout << sum_waiting_time << endl;

    return 0;
}