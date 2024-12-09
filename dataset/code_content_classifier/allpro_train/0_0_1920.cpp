#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MASK = (1 << 30) - 1;

int main() {
    int n;
    cin >> n;

    string S = "";
    vector<int> W;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        char c;
        int w;
        cin >> c >> w;

        // Perform cyclic shift on character
        c = (c - 'a' + ans) % 26 + 'a';

        // Update w
        w = w ^ (ans & MASK);

        S += c;
        W.push_back(w);

        int sum = 0;
        for (int j = 0; j < S.length(); j++) {
            int min_val = W[j];
            for (int k = j; k < S.length(); k++) {
                if (S[k] == S[k - j]) {
                    min_val = min(min_val, W[k]);
                    sum += min_val;
                } else {
                    break;
                }
            }
        }

        ans = sum;
        cout << ans << endl;
    }

    return 0;
}