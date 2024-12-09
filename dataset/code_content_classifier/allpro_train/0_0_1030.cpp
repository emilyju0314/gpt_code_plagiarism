#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int count_J = 0;
    int count_O = 0;
    int count_I = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'J') {
            count_J++;
        } else if (S[i] == 'O') {
            count_O = min(count_J, count_O + 1);
        } else if (S[i] == 'I') {
            ans = max(ans, min(count_O, count_I));
            count_I++;
        }
    }

    cout << ans << endl;

    return 0;
}