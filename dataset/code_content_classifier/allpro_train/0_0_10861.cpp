#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string cards;
        cin >> cards;

        vector<pair<int, int>> ways;

        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                int a = i;
                int b = 12 / i;

                bool can_win = false;
                for (int j = 0; j < b; j++) {
                    bool win = true;
                    for (int k = 0; k < a; k++) {
                        if (cards[j + k * b] != 'X') {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        can_win = true;
                        break;
                    }
                }

                if (can_win) {
                    ways.push_back({a, b});
                }
            }
        }

        cout << ways.size();
        for (auto way : ways) {
            cout << " " << way.first << "x" << way.second;
        }
        cout << endl;
    }

    return 0;
}