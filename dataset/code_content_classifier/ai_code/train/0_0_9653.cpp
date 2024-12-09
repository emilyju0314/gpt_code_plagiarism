#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }

    int m = patterns[0].size();
    string result = patterns[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (patterns[i][j] != result[j]) {
                result[j] = '?';
            }
        }
    }

    cout << result << endl;

    return 0;
}