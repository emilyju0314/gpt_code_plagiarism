#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = abs(lines[i].first - lines[i].second) - 1;
    }

    sort(dist.begin(), dist.end());

    int ways = 1;
    if (dist[0] == dist[n/2] && dist[n/2] == dist[n-1]) {
        ways = 1;
        for (int i = 0; i < (n/2); i++) {
            if (dist[i] == dist[i+1]) {
                ways++;
            } else {
                break;
            }
        }
    }

    cout << ways << endl;
    
    return 0;
}