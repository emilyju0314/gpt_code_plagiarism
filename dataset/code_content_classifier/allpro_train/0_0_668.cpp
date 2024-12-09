#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int count_aa = 0, count_bb = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            count_aa++;
            i++;
        } else if (s[i] == 'b' && s[i + 1] == 'b') {
            count_bb++;
            i++;
        }
    }

    long long result = 1;
    for (int i = 0; i < count_aa; i++) {
        result = (result * 2) % MOD;
    }
    for (int i = 0; i < count_bb; i++) {
        result = (result * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}