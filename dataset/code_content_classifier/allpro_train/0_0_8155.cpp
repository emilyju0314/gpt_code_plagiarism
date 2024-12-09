#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse a substring within a string
void reverseSubstring(string& s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string minString = s;
        int minK = 1;

        for (int k = 1; k <= n; k++) {
            string temp = s;
            for (int i = 0; i <= n-k; i++) {
                reverseSubstring(temp, i, i+k-1);
            }
            if (temp < minString) {
                minString = temp;
                minK = k;
            }
        }

        cout << minString << endl;
        cout << minK << endl;
    }

    return 0;
}