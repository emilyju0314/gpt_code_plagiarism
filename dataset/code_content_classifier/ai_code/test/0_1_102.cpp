#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> start_position(int n, int m, string s) {
    int left = 0, right = 0, up = 0, down = 0;
    for (char c : s) {
        if (c == 'L') {
            left++;
        } else if (c == 'R') {
            right++;
        } else if (c == 'U') {
            up++;
        } else {
            down++;
        }
    }

    int x = 1 + min(right, m) - min(left, m);
    int y = 1 + min(down, n) - min(up, n);

    return {y, x};
}

int main() {
    int t;
    cin >> t;

    vector<pair<int, int>> answers;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        answers.push_back(start_position(n, m, s));
    }

    for (pair<int, int> answer : answers) {
        cout << answer.first << " " << answer.second << endl;
    }

    return 0;
}