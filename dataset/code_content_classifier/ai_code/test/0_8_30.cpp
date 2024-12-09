#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        map<char, vector<int>> occurrence;

        for (int i = 0; i < n; i++) {
            occurrence[s[i]].push_back(i);
        }

        int ans = -1;

        for (auto& it : occurrence) {
            if (it.second.size() >= 2) {
                int i = 0, j = it.second.size() - 1;
                int erased = 0;

                while (i < j) {
                    if (s[it.second[i]] != s[it.second[j]) {
                        erased += it.second[j] - it.second[i] - 1;
                    }
                    i++;
                    j--;
                }

                if (ans == -1 || erased < ans)
                    ans = erased;
            }
        }

        cout << ans << endl;
    }

    return 0;
}