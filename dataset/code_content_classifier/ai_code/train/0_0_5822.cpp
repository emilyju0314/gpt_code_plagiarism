#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int result = 0;
    int prev = 0, curr = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[curr]) {
            curr++;
            int width = i - prev + 1;
            if (curr == m) {
                result = max(result, width);
                prev = i;
            }
        }
    }

    cout << result << endl;

    return 0;
}