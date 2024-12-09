#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;

    cin >> N >> S;

    string result;
    int a_count = 0, b_count = 0;

    for (int i = 0; i < 2*N; i++) {
        if (S[i] == 'a' && a_count < N) {
            result += S[i];
            a_count++;
        } else if (S[i] == 'b' && b_count < N) {
            result += S[i];
            b_count++;
        }
    }

    cout << result << endl;

    return 0;
}