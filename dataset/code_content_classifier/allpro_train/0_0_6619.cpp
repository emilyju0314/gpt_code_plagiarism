#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<int> wc(26);
    for (int i = 0; i < 26; i++) {
        cin >> wc[i];
    }

    int max_val = 0;
    for (int i = 0; i < s.size(); i++) {
        max_val += wc[s[i] - 'a'] * (i + 1);
    }

    int max_wc = *max_element(wc.begin(), wc.end());

    for (int i = s.size() + 1; i <= s.size() + k; i++) {
        max_val += max_wc * i;
    }

    cout << max_val << endl;

    return 0;
}