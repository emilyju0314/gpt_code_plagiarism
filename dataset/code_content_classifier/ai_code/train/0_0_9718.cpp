#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int k;

    cin >> s;
    cin >> k;

    vector<string> substrings;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            substrings.push_back(s.substr(i, j));
        }
    }

    sort(substrings.begin(), substrings.end());
    
    if (k > substrings.size()) {
        cout << "No such line." << endl;
    } else {
        cout << substrings[k - 1] << endl;
    }

    return 0;
}