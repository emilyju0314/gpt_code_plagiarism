#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidGuess(string guess, string num, int hit, int blow) {
    int hitCount = 0, blowCount = 0;
    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] == num[i]) {
            hitCount++;
        } else if (num.find(guess[i]) != string::npos) {
            blowCount++;
        }
    }
    return (hitCount == hit && blowCount == blow);
}

void identifyNumber(int L, int H, vector<pair<string, pair<int, int>>> hints) {
    string num = "0123456789";
    do {
        bool valid = true;
        for (auto hint : hints) {
            if (!isValidGuess(hint.first, num, hint.second.first, hint.second.second)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << num << endl;
            return;
        }
    } while (next_permutation(num.begin(), num.begin() + L));
    cout << "NO" << endl;
}

int main() {
    int L, H;
    while (cin >> L >> H) {
        if (L == 0 && H == 0) break;
        
        vector<pair<string, pair<int, int>>> hints;
        for (int i = 0; i < H; i++) {
            string tryNum;
            int hit, blow;
            cin >> tryNum >> hit >> blow;
            hints.push_back({tryNum, {hit, blow}});
        }
        identifyNumber(L, H, hints);
    }
    return 0;
}