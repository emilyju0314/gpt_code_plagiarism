#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<set<int>> sets(m);
    set<int> all_elements;
    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        
        for (int j = 0; j < sz; j++) {
            int element;
            cin >> element;
            sets[i].insert(element);
            all_elements.insert(element);
        }
    }

    vector<int> element_positions(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (sets[j].count(i)) element_positions[i] = j;
        }
    }

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= max(1, i - d); j--) {
            dp[i] = min(dp[i], dp[j - 1] + (element_positions[i] != element_positions[j]));
        }
    }

    int answer = 1e9;
    for (int i = n - d + 1; i <= n; i++) {
        answer = min(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}