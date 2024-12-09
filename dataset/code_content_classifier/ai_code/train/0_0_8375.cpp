#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> starts, ends;

    // Find the indices where a zebra subsequence starts and ends
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            starts.push_back(i);
        }
    }

    if (starts.size() % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    starts.push_back(s.length());

    // Output the resulting zebra subsequences
    cout << starts.size() / 2 << endl;
    for (int i = 0; i < starts.size(); i += 2) {
        int length = starts[i+1] - starts[i] + 1;
        cout << length;
        for (int j = starts[i]; j <= starts[i+1]; j++) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}