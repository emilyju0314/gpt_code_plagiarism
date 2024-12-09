#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<vector<pair<int, int>>> segments(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<pair<int, int>> segment(k);
        for (int j = 0; j < k; j++) {
            cin >> segment[j].first >> segment[j].second;
        }
        segments[i] = segment;
    }

    int leads = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int lead_count = 0;
            int lead_i = 0, lead_j = 0;
            int dist_i = 0, dist_j = 0;
            while (lead_i < segments[i].size() && lead_j < segments[j].size()) {
                int di = segments[i][lead_i].first * segments[i][lead_i].second;
                int dj = segments[j][lead_j].first * segments[j][lead_j].second;
                if (di <= dj) {
                    dist_i += di;
                    lead_i++;
                }
                if (dj <= di) {
                    dist_j += dj;
                    lead_j++;
                }
                if (dist_i > dist_j && dist_i < s && dist_j < s) {
                    lead_count++;
                }
            }
            leads += lead_count;
        }
    }

    cout << leads << endl;

    return 0;
}