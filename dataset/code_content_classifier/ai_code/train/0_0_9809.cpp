#include <iostream>

using namespace std;

int main() {
    long long k;
    cin >> k;

    string s = "codeforces";
    int len = s.length();

    long long count = 1;
    int i = 0;
    while (count < k) {
        count /= len - i;
        count *= len - i - 1;
        i = (i + 1) % len;
    }

    for (int j = 0; j < len; j++) {
        for (int l = 0; l < count; l++) {
            cout << s[j];
        }
    }

    return 0;
}