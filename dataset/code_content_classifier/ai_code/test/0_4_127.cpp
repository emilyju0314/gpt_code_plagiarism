#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;

        vector<int> count(26, 0); // Count occurrences of each character in S
        for(char c : S) {
            count[c - 'a']++;
        }

        string result;
        for(char c : T) {
            result += string(count[c - 'a'], c); // Append T to result
            count[c - 'a'] = 0; // Set count of character in T to 0
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                result += string(count[i], 'a' + i); // Append remaining characters to result
            }
        }

        cout << result << endl;
    }

    return 0;
}