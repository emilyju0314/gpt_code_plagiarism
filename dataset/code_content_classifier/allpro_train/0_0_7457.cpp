#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> guesses(m);
    for (int i = 0; i < m; i++) {
        cin >> guesses[i];
    }

    long long ans = 1;
    int prev_guess = 0;

    for (int i = 0; i < m; i++) {
        int guess = guesses[i];

        if (guess < prev_guess) {
            ans += (prev_guess - guess);
        } else {
            ans += (guess - prev_guess);
        }

        prev_guess = guess;
    }

    cout << (ans - 1) << endl;

    return 0;
}