#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> counter;

    for (char c : s)
        counter[c]++;

    for (char c : t) {
        if (counter.find(c) == counter.end() || counter[c] == 0)
            return false;
        counter[c]--;
    }

    return true;
}

int main() {
    string s, t;

    while (cin >> s >> t) {
        if (isAnagram(s, t))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
