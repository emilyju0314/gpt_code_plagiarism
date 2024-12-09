#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    long long count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') ones++;
            if (ones == k) count++;
            if (ones > k) break;
        }
    }

    cout << count << endl;

    return 0;
}