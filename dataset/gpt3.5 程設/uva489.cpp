#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int round;
    while (cin >> round && round != -1) {
        string answer, guess;
        cin >> answer >> guess;

        set<char> correctChars(answer.begin(), answer.end());
        set<char> guessedChars;

        int wrongGuesses = 0;
        for (char c : guess) {
            if (correctChars.count(c) == 0 && guessedChars.count(c) == 0) {
                wrongGuesses++;
                guessedChars.insert(c);
            }
            else if (correctChars.count(c) == 1) {
                guessedChars.insert(c);
                correctChars.erase(c);
            }

            if (correctChars.empty())
                break;
        }

        cout << "Round " << round << endl;
        if (correctChars.empty() && wrongGuesses < 7)
            cout << "You win." << endl;
        else if (wrongGuesses >= 7)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
    }

    return 0;
}
