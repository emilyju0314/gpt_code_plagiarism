#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    string T = S;
    reverse(T.begin(), T.end());
    string U = S + T;

    string minString = U;
    for (int i = 1; i <= K; i++) {
        string newString = U.substr(0, N);
        reverse(newString.begin(), newString.end());
        newString += U.substr(N);
        
        minString = min(minString, newString);
        U = newString;
    }

    cout << minString << endl;

    return 0;
}