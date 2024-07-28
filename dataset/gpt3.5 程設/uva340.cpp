#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, guessNum = 0;
    while (cin >> n && n) {
        cout << "Game " << ++guessNum << ":" << endl;
        vector<int> secretCode(n);
        for (int i = 0; i < n; ++i)
            cin >> secretCode[i];

        while (true) {
            vector<int> guess(n);
            for (int i = 0; i < n; ++i)
                cin >> guess[i];

            if (guess[0] == 0) // 0 0 0 0 ... 0表示結束遊戲
                break;

            int strong = 0, weak = 0;
            vector<int> secretFreq(10, 0), guessFreq(10, 0);

            for (int i = 0; i < n; ++i) {
                if (secretCode[i] == guess[i])
                    ++strong;
                else {
                    ++secretFreq[secretCode[i]];
                    ++guessFreq[guess[i]];
                }
            }

            for (int i = 1; i < 10; ++i)
                weak += min(secretFreq[i], guessFreq[i]);

            cout << "    (" << strong << "," << weak << ")" << endl;
        }
    }
    return 0;
}
