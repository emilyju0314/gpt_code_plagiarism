#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, s;
    cin >> n >> l >> s;

    vector<int> locations(n);
    for (int i = 0; i < n; i++) {
        cin >> locations[i];
    }

    // Calculating total distance to visit all men
    long long total_distance = 0;
    for (int i = 0; i < n - 1; i++) {
        total_distance += abs(locations[i] - locations[i+1]);
    }

    // Checking if it is possible to visit all men with given tickets
    if (l >= n-1) {
        cout << total_distance << endl;

        for (int i = 1; i <= n-1; i++) {
            cout << i << " ";
        }
        cout << endl;
    } else if (l == 0 || (s == 1 && l < n-1)) {
        cout << -1 << endl;
    } else {
        vector<int> visited;
        
        visited.push_back(s);
        vector<bool> visited_flag(n, false);
        visited_flag[s-1] = true;
        
        vector<pair<int, int>> distances;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                distances.push_back(make_pair(abs(locations[s-1] - locations[i-1]), i));
            }
        }
        sort(distances.begin(), distances.end());

        for (int i = 1; i <= l; i++) {
            int next_location = distances[distances.size() - i].second;
            visited.push_back(next_location);
            visited_flag[next_location - 1] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!visited_flag[i-1]) {
                visited.push_back(i);
            }
        }

        long long new_total_distance = 0;
        for (int i = 0; i < n - 1; i++) {
            new_total_distance += abs(locations[visited[i]-1] - locations[visited[i+1]-1]);
        }

        cout << new_total_distance << endl;
        for (int i = 0; i < n-1; i++) {
            cout << visited[i] << " ";
        }
        cout << endl;
    }

    return 0;
}