#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<int> left(n, 0), right(n, 0), up(m, 0), down(m, 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                left[0]++;
            } else if (s[i] == 'R') {
                right[n-1]++;
            } else if (s[i] == 'U') {
                up[0]++;
            } else {
                down[m-1]++;
            }
        }

        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] + (s[i-1] == 'L' ? 1 : 0);
        }

        for (int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] + (s[i] == 'R' ? 1 : 0);
        }

        for (int i = 1; i < m; i++) {
            up[i] = up[i-1] + (s[i-1] == 'U' ? 1 : 0);
        }

        for (int i = m-2; i >= 0; i--) {
            down[i] = down[i+1] + (s[i] == 'D' ? 1 : 0);
        }

        int max_commands = 0, start_row = 1, start_col = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int total_commands = left[i] + right[i] + up[j] + down[j];
                if (total_commands > max_commands) {
                    max_commands = total_commands;
                    start_row = i+1;
                    start_col = j+1;
                }
            }
        }

        cout << start_row << " " << start_col << endl;
    }

    return 0;
}