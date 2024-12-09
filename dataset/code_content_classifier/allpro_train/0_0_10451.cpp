#include <iostream>

using namespace std;

bool isPossible(string S, string T, int a, int b, int c, int d) {
    // Check if the lengths of the substrings are different
    if ((b - a) != (d - c)) {
        return false;
    }
    
    // Check if the characters in the substrings are the same
    for (int i = a - 1, j = c - 1; i < b; i++, j++) {
        if (S[i] != T[j]) {
            return false;
        }
    }
    
    // Check if the number of 'B's in T is not greater than the number of 'A's in S
    int countA = 0, countB = 0;
    for (char ch : S) {
        if (ch == 'A') {
            countA++;
        }
    }
    for (char ch : T) {
        if (ch == 'B') {
            countB++;
        }
    }
    if (countB > countA) {
        return false;
    }
    
    return true;
}

int main() {
    string S, T;
    int Q;
    
    cin >> S >> T >> Q;
    
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        if (isPossible(S, T, a, b, c, d)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    
    return 0;
}