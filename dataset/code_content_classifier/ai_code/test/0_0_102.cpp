#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int x = 0, y = 0, max_commands = 0, start_x = 1, start_y = 1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'L') {
                y--;
            } else if(s[i] == 'R') {
                y++;
            } else if(s[i] == 'U') {
                x--;
            } else {
                x++;
            }

            dp[x][y] = i+1;

            if(dp[x][y] > max_commands) {
                max_commands = dp[x][y];
                start_x = x + 1;
                start_y = y + 1;
            }
        }

        cout << start_x << " " << start_y << endl;
    }

    return 0;
}