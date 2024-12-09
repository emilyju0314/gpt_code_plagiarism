#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int max_length = 0;
    for (int len = 1; len < N; len++) {
        for (int l1 = 0; l1 + len < N; l1++) {
            for (int l2 = l1 + len; l2 + len <= N; l2++) {
                bool match = true;
                for (int i = 0; i < len; i++) {
                    if (S[l1 + i] != S[l2 + i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    max_length = max(max_length, len);
                }
            }
        }
    }

    cout << max_length << endl;

    return 0;
}