#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> strings(n);
    vector<vector<int>> cost(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    int total_cost = 0;
    for(int j = 0; j < m; j++) {
        vector<int> char_count(26, 0);
        for(int i = 0; i < n; i++) {
            char_count[strings[i][j]-'a']++;
        }

        int max_count = *max_element(char_count.begin(), char_count.end());
        int position_cost = INT_MAX;
        for(int k = 0; k < 26; k++) {
            int current_cost = 0;
            for(int l = 0; l < 26; l++) {
                if(l != k) {
                    current_cost += char_count[l] * cost[l][j];
                }
            }

            position_cost = min(position_cost, current_cost);
        }

        total_cost += position_cost;
    }

    cout << total_cost << endl;

    return 0;
}