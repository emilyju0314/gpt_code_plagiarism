#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count[3] = {0}; // Store counts of '0', '1', '2'

    // Count occurrences of each character in the input string
    for (char c : s) {
        count[c - '0']++;
    }

    // Calculate the target counts for each character
    int target = n / 3;
    
    // Replace characters with '0' to balance the string
    for (int i = 0; i < 3; i++) {
        if (count[i] > target) {
            while (count[i] > target) {
                for (int j = n - 1; j >= 0; j--) {
                    if (s[j] - '0' == i) {
                        s[j] = '0';
                        count[i]--;
                        break;
                    }
                }
            }
        }
    }

    // Replace characters with '1' to balance the string
    for (int i = 0; i < 3; i++) {
        if (count[i] < target) {
            while (count[i] < target) {
                for (int j = 0; j < n; j++) {
                    if (s[j] - '0' == i) {
                        s[j] = '1';
                        count[i]++;
                        break;
                    }
                }
            }
        }
    }

    cout << s << endl;

    return 0;
}