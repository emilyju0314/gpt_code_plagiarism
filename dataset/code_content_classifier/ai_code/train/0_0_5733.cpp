#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;
        
        int score = 0;
        int aliceScore = 0;
        bool isAliceTurn = true;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                score++;
            } else {
                if(isAliceTurn) {
                    aliceScore += (score + 1) / 2;
                }
                score = 0;
                isAliceTurn = !isAliceTurn;
            }
        }

        if(isAliceTurn) {
            aliceScore += (score + 1) / 2;
        }

        cout << aliceScore << endl;
    }

    return 0;
}