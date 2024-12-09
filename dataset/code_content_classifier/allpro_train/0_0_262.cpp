#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;

        int n = s.length();
        int x_min = 0, x_max = 0, y_min = 0, y_max = 0;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'W') {
                y++;
            } else if(s[i] == 'S') {
                y--;
            } else if(s[i] == 'A') {
                x--;
            } else if(s[i] == 'D') {
                x++;
            }
            x_min = min(x_min, x);
            x_max = max(x_max, x);
            y_min = min(y_min, y);
            y_max = max(y_max, y);
        }

        int area1 = (x_max - x_min + 1) * (y_max - y_min + 1);

        int area2 = INT_MAX;
        for(int i = 0; i <= n; i++) {
            int x_add = 0, y_add = 0;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    if(s[j] == 'W') {
                        y++;
                    } else if(s[j] == 'S') {
                        y--;
                    } else if(s[j] == 'A') {
                        x--;
                    } else if(s[j] == 'D') {
                        x++;
                    }
                }
                x_add = min(x_add, x);
                y_add = min(y_add, y);
            }
            int temp_area = (max(x_max, x_add) - min(x_min, x_add) + 1) * (max(y_max, y_add) - min(y_min, y_add) + 1);
            area2 = min(area2, temp_area);
        }

        cout << min(area1, area2) << endl;
    }

    return 0;
}