#include <iostream>
#include <string>

using namespace std;

int countMatchingSubstrings(string S, string T) {
    int count = 0;

    for (int i = 0; i <= S.length() - T.length(); i++) {
        int diffCount = 0;
        for (int j = 0; j < T.length(); j++) {
            if (S[i+j] != T[j]) {
                diffCount++;
            }
        }
        if (diffCount == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    string S, T;
    cin >> S >> T;

    int result = countMatchingSubstrings(S, T);
    cout << result << endl;

    return 0;
}