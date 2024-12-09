#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    vector<char> result;
    for (int i = 0; i < s.length(); ++i) {
        while (!result.empty() && result.back() > s[i] && result.size() + s.length() - i - 1 >= k) {
            result.pop_back();
        }
        if (result.size() < k) {
            result.push_back(s[i]);
        }
    }

    for (char c : result) {
        cout << c;
    }
    cout << endl;

    return 0;
}