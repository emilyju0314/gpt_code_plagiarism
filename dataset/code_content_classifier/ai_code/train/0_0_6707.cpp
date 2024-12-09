#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
    }

    stack<char> brackets;
    string result = "";

    for (int i = 0; i < n; i++) {
        if (brackets.empty()) {
            brackets.push('(');
            result += '(';
        }

        int dist = segments[i].first;
        for (int j = 0; j < dist; j++) {
            brackets.push('(');
            result += '(';
        }

        dist = segments[i].second - segments[i].first;
        for (int j = 0; j < dist; j++) {
            if (brackets.empty()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            brackets.pop();
            result += ')';
        }
    }

    if (!brackets.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}