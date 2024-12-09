#include <iostream>
#include <vector>
#include <string>

using namespace std;

int w[12];
vector<string> strings;

int calcWu(string s, string t) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) result += w[i];
    }
    return result;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    for (int i = 0; i < q; i++) {
        string t;
        int k, count = 0;
        cin >> t >> k;

        for (int j = 0; j < m; j++) {
            if (calcWu(strings[j], t) <= k) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}