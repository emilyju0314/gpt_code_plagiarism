#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ab_count = 0, ba_count = 0;
        int n = s.length();

        // Count occurrences of "ab" and "ba"
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') {
                ab_count++;
            }
            if (s[i] == 'b' && s[i + 1] == 'a') {
                ba_count++;
            }
        }

        // Make the necessary changes to balance the counts
        if (ab_count > ba_count) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'a' && s[i + 1] == 'b') {
                    s[i + 1] = 'a';
                    break;
                }
            }
        } else if (ba_count > ab_count) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'b' && s[i + 1] == 'a') {
                    s[i] = 'b';
                    break;
                }
            }
        }

        // Print the modified string
        cout << s << endl;
    }

    return 0;
}