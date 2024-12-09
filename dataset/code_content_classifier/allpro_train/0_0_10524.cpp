#include <bits/stdc++.h>
using namespace std;

const int MAX = 500005;
int cnt[MAX];
int cost[MAX];

int main() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            string sub = "";
            for (int k = j; k < s.size(); k++) {
                sub += s[k];
                cnt[hash<string>{}(sub)]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int max_value = 0;
    for (int i = 0; i < MAX; i++) {
        max_value = max(max_value, cnt[i] * cost[i]);
    }

    cout << max_value << endl;

    return 0;
}