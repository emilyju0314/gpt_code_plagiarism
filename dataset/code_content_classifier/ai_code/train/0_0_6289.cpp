#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    string s, t;
    cin >> n >> s >> m >> t;

    int count = 0;
    for (int i = 0; i <= n - m; i++) {
        int replacements = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                replacements++;
            }
        }
        count = max(count, replacements);
    }

    cout << count << endl;

    return 0;
}