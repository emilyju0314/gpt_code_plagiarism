#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;

        int zero_count = 0, one_count = 0;
        for (char ch : s) {
            if (ch == '0') {
                zero_count++;
            } else {
                one_count++;
            }
        }

        int total_cost = min(zero_count * c0 + one_count * c1, min(zero_count * h + n * c1, one_count * h + n * c0));
        cout << total_cost << endl;
    }

    return 0;
}