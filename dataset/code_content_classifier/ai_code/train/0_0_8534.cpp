#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> message(n);
    for (int i = 0; i < n; i++) {
        cin >> message[i];
    }

    int q;
    cin >> q;

    unordered_map<string, int> memo;

    while (q--) {
        int l, r;
        cin >> l >> r;

        string substring = "";
        for (int i = l-1; i < r; i++) {
            substring += to_string(message[i]);
        }

        string current_encoding = "";
        int min_length = 0;

        for (int i = 0; i < substring.length(); i++) {
            current_encoding += substring[i];
            if (memo.find(current_encoding) != memo.end()) {
                min_length = max(min_length, memo[current_encoding]);
            }
        }

        cout << substring.length() - min_length << endl;
        memo[substring] = max(memo[substring], substring.length() - min_length);
    }

    return 0;
}