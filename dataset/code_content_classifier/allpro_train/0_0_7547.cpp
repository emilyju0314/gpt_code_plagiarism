#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string a, b, s;
    cin >> a >> b >> s;

    auto getLPS = [](const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m);
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    };

    auto matchCount = [&](const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> lps = getLPS(pattern + "#" + text);

        int count = 0;
        for (int i = m + 1; i < m + 1 + n; i++) {
            if (lps[i] == m) {
                count++;
            }
        }

        return count;
    };

    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += matchCount(a.substr(i-1, n-i+1), s);
    }

    cout << count << endl;

    return 0;
}