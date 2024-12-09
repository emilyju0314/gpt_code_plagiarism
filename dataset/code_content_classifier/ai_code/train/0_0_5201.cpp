#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int cnt_0 = 0, cnt_1 = 0;
    for (char c : s) {
        if (c == '0') {
            cnt_0++;
        } else {
            cnt_1++;
        }
    }

    string result = "";
    int t_0 = 0, t_1 = 0;
    for (char c : t) {
        if (c == '0') {
            t_0++;
        } else {
            t_1++;
        }
    }

    int max_occurrences = min(cnt_0 / t_0, cnt_1 / t_1);

    int remaining_0 = cnt_0 - max_occurrences * t_0;
    int remaining_1 = cnt_1 - max_occurrences * t_1;

    for (char c : s) {
        if (c == '0' && remaining_0 > 0) {
            result += '0';
            remaining_0--;
        } else if (c == '1' && remaining_1 > 0) {
            result += '1';
            remaining_1--;
        } else {
            result += c;
        }
    }

    cout << result << endl;

    return 0;
}