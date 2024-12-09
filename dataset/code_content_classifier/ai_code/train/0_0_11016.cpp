#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int count_s_0 = 0, count_s_1 = 0;
    int count_t_0 = 0, count_t_1 = 0;

    // Count the number of 0s and 1s in s and t
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            count_s_0++;
        } else {
            count_s_1++;
        }

        if(t[i] == '0') {
            count_t_0++;
        } else {
            count_t_1++;
        }
    }

    // If the number of 0s and 1s in s and t do not match, it is impossible to convert s to t
    if(count_s_0 != count_t_0 || count_s_1 != count_t_1) {
        cout << -1 << endl;
        return 0;
    }

    // Find the maximum number of rotations needed
    int rotations = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            rotations++;
        }
    }

    cout << rotations / 2 << endl;

    return 0;
}