#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> initial_direction(n);
        vector<pair<int, int>> final_direction(n);

        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            initial_direction[i] = {u - x, v - y};

            // Rotate the initial direction vector by 90 degrees to get the final direction
            final_direction[i] = {-initial_direction[i].second, initial_direction[i].first};
        }

        unordered_map<int, int> slopes_map;
        long long eye_contact_pairs = 0;

        for (int i = 0; i < n; i++) {
            int gcd_val = gcd(final_direction[i].first, final_direction[i].second);
            final_direction[i].first /= gcd_val;
            final_direction[i].second /= gcd_val;
            
            int slope_hash = final_direction[i].first * 1000000007 + final_direction[i].second;

            if (slopes_map.find(slope_hash) != slopes_map.end()) {
                eye_contact_pairs += slopes_map[slope_hash];
            }

            slopes_map[slope_hash]++;
        }

        cout << eye_contact_pairs << endl;
    }

    return 0;
}