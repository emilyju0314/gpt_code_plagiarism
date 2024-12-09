#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> suffixes;

    for(int i = 4; i < s.length(); i++) {
        string suffix = s.substr(i, 2);
        suffixes.insert(suffix);
        if(i+2 < s.length()) {
            suffix = s.substr(i, 3);
            suffixes.insert(suffix);
        }
    }

    cout << suffixes.size() << endl;
    for(auto it = suffixes.begin(); it != suffixes.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}