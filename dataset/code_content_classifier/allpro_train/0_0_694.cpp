#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    unordered_set<string> uniqueStrings;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            string prefixS = s.substr(0, i);
            string prefixT = t.substr(0, j);
            uniqueStrings.insert(prefixS + prefixT);
        }
    }

    cout << uniqueStrings.size() << endl;

    return 0;
}