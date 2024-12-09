#include <iostream>
#include <vector>

using namespace std;

bool checkWin(vector<int>& cards) {
    for(int card : cards) {
        if(card != 0) {
            return false;
        }
    }
    return true;
}

string determineWinner(int firstPlayer, vector<int>& alice, vector<int>& bob) {
    if(firstPlayer == 0) {
        if(checkWin(alice)) {
            return "Alice";
        }
    } else {
        if(checkWin(bob)) {
            return "Bob";
        }
    }

    int winner = 0; // 0 for no winner

    for(int i = 0; i < 1000; i++) {
        int a = alice[i % 8];
        int b = bob[i % 8];

        if(a == 0 && b == 0) {
            winner = firstPlayer;
            break;
        }

        int c = (a + b) % 5;
        alice[i % 8] = c;

        if(checkWin(alice)) {
            winner = 0;
            break;
        }

        swap(alice, bob);
    }

    if(winner == 0) {
        return "Deal";
    } else if(winner == 1) {
        return "Alice";
    } else {
        return "Bob";
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int firstPlayer;
        cin >> firstPlayer;

        vector<int> alice(8);
        vector<int> bob(8);

        for(int i = 0; i < 8; i++) {
            cin >> alice[i];
        }

        for(int i = 0; i < 8; i++) {
            cin >> bob[i];
        }

        cout << determineWinner(firstPlayer, alice, bob) << endl;
    }

    return 0;
}