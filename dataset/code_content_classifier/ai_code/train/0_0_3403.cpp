#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findLexicographicallyMaxSubsequence(string s) {
    vector<int> count(26, 0);
    string result = "";

    for (char c : s) {
        count[c - 'a']++;
    }

    for (char c : s) {
        count[c - 'a']--;
        if (result.empty() || c > result.back()) {
            while (!result.empty() && c > result.back() && count[result.back() - 'a'] > 0) {
                result.pop_back();
            }
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    string result = findLexicographicallyMaxSubsequence(s);

    cout << result << endl;

    return 0;
}