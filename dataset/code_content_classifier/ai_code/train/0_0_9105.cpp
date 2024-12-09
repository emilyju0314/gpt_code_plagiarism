#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> substrings;

    // Add all substrings of s
    for (int i = 0; i < s.length(); i++) {
        for (int j = i+1; j <= s.length(); j++) {
            substrings.insert(s.substr(i, j-i));
        }
    }

    // Add all substrings of t_i
    for (int i = 0; i < s.length(); i++) {
        string t_i = s;
        t_i[i] = '*';
        for (int j = 0; j < t_i.length(); j++) {
            for (int k = j+1; k <= t_i.length(); k++) {
                substrings.insert(t_i.substr(j, k-j));
            }
        }
    }

    cout << substrings.size() << endl;

    return 0;
}