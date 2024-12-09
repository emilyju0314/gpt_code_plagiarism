#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<string> substrings;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            substrings.push_back(s.substr(j, i));
        }
    }

    sort(substrings.begin(), substrings.end());
    reverse(substrings.begin(), substrings.end());

    cout << substrings[k-1] << endl;

    return 0;
}