#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<int> s(m);
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }

        sort(s.begin(), s.end());

        // Calculate the distance between the hooligan and the guard
        int dist = abs(b - a) - 1;

        // Initialize the maximum number of firecrackers that can explode
        int maxFirecrackers = 0;

        // If there are firecrackers that explode before the guard reaches the hooligan
        if (dist - 1 >= m) {
            maxFirecrackers = m;
        } else {
            // Calculate the maximum number of firecrackers that can explode before the hooligan is caught
            maxFirecrackers = min(dist, m);
        }

        cout << maxFirecrackers << endl;
    }

    return 0;
}