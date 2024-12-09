#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int yay = 0, whoops = 0;
    int s_count[26] = {0};
    int t_count[26] = {0};

    for (char c : s) {
        if (islower(c)) {
            s_count[c - 'a']++;
        } else {
            s_count[c - 'A']++;
        }
    }

    for (char c : t) {
        if (islower(c)) {
            t_count[c - 'a']++;
        } else {
            t_count[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int common = min(s_count[i], t_count[i]);
        yay += common;
        s_count[i] -= common;
        t_count[i] -= common;
    }

    for (int i = 0; i < 26; i++) {
        if (islower('a' + i)) {
            int common = min(s_count[i], t_count[i]);
            whoops += common;
        } else {
            int common = min(s_count[i], t_count[i]);
            whoops += common;
        }
    }

    cout << yay << " " << whoops << endl;

    return 0;
}