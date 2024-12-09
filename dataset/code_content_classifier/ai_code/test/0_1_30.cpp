#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int left = 0, right = n - 1;
        int changes = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                if (freq[s[left]] >= 2) {
                    freq[s[left]] -= 2;
                    left++;
                    right--;
                    changes++;
                } else if (freq[s[right]] >= 2) {
                    freq[s[right]] -= 2;
                    left++;
                    right--;
                    changes++;
                } else {
                    changes = -1;
                    break;
                }
            } else {
                left++;
                right--;
            }
        }

        cout << changes << endl;
    }

    return 0;
}