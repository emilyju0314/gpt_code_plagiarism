#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n;
    cin >> n;

    unordered_map<char, unordered_map<char, int>> cost;
    for (int i = 0; i < n; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        cost[a][b] = w;
    }

    int min_cost = INT_MAX;
    string result = "";

    for (int i = 0; i <= s.size(); i++) {
        string temp_s = s;
        string temp_t = t;
        int current_cost = 0;
        bool valid = true;

        for (int j = 0; j < s.size(); j++) {
            if (j < i) {
                if (temp_s[j] != temp_t[j]) {
                    if (cost[temp_s[j]][temp_t[j]] == 0) {
                        valid = false;
                        break;
                    } else {
                        current_cost += cost[temp_s[j]][temp_t[j]];
                        temp_s[j] = temp_t[j];
                    }
                }
            } else if (j >= i) {
                if (temp_s[j] != temp_t[j - i]) {
                    if (cost[temp_s[j]][temp_t[j - i]] == 0) {
                        valid = false;
                        break;
                    } else {
                        current_cost += cost[temp_s[j]][temp_t[j - i]];
                        temp_s[j] = temp_t[j - i];
                    }
                }
            }
        }

        if (valid && current_cost < min_cost) {
            min_cost = current_cost;
            result = temp_s;
        }
    }

    if (min_cost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
        cout << result << endl;
    }

    return 0;
}