#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; // Convert 1-indexed to 0-indexed
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = i;
        vector<bool> visited(n, false);

        for(int j = 0; j < k; j++) { // Reconnect line segments
            x = a[x];
        }

        vector<int> cycle;
        while(!visited[x]) {
            visited[x] = true;
            cycle.push_back(x);
            x = a[x];
        }

        int cnt = 0;
        for(int j = 0; j < cycle.size(); j++) {
            for(int l = 0; l < cycle.size(); l++) {
                if(a[cycle[j]] == cycle[l]) {
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt / 2);
    }

    cout << ans << endl;

    return 0;
}