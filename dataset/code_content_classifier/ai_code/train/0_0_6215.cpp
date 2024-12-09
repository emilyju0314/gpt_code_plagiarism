#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, a, b;
    cin >> N >> a >> b;
    
    vector<pair<int, int>> pinholes(N);
    for (int i = 0; i < N; i++) {
        cin >> pinholes[i].first >> pinholes[i].second;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist_ab = abs(pinholes[a-1].first - pinholes[b-1].first) + abs(pinholes[a-1].second - pinholes[b-1].second);
            int dist_ij = abs(pinholes[i].first - pinholes[j].first) + abs(pinholes[i].second - pinholes[j].second);
            int dist_ia = abs(pinholes[i].first - pinholes[a-1].first) + abs(pinholes[i].second - pinholes[a-1].second);
            int dist_ib = abs(pinholes[i].first - pinholes[b-1].first) + abs(pinholes[i].second - pinholes[b-1].second);
            int dist_ja = abs(pinholes[j].first - pinholes[a-1].first) + abs(pinholes[j].second - pinholes[a-1].second);
            int dist_jb = abs(pinholes[j].first - pinholes[b-1].first) + abs(pinholes[j].second - pinholes[b-1].second);

            if ((dist_ab == dist_ij) && (dist_ia == dist_jb || dist_ib == dist_ja)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}