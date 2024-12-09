#include <iostream>
#include <string>

using namespace std;

int main() {
    int L;
    string S;
    cin >> L >> S;

    int captured = 0;

    for (int i = 0; i < L; i++) {
        if (S[i] == '.') {
            // Check if can capture white stones
            int start = i - 1, end = i + 1;
            int blackCaptured = 0;

            // Check black stones surrounding white stone
            while (start >= 0 && end < L && S[start] == 'B' && S[end] == 'B') {
                start--;
                end++;
                blackCaptured++;
            }

            captured = max(captured, blackCaptured);
        }
    }

    cout << captured << endl;

    return 0;
}