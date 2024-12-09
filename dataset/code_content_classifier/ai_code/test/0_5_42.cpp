#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n+1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = {a, b};
    }

    sort(tasks.begin()+1, tasks.end());

    int t;
    cin >> t;
    vector<int> s(t);
    for (int i = 0; i < t; i++) {
        cin >> s[i];
    }

    vector<int> completion(n+1, -1);
    int totalTime = 0, completed = 0, ans = 0;

    for (int i = 1; i <= n; i++) {
        totalTime = max(totalTime, tasks[i].second);
        if (completion[tasks[i].first] == -1) {
            completion[tasks[i].first] = tasks[i].second;
            if (find(s.begin(), s.end(), tasks[i].first) != s.end()) {
                completed++;
            }
        }
        if (completed == t) {
            ans = (ans + totalTime - tasks[i].first + 1) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}