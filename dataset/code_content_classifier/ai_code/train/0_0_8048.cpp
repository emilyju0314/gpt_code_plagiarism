#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int D;
    cin >> D;

    int x;
    cin >> x;

    vector<pair<char, int>> answersWithOneBlank(x);
    for (int i = 0; i < x; i++) {
        char answer;
        int score;
        cin >> answer >> score;
        answersWithOneBlank[i] = {answer, score};
    }

    int y;
    cin >> y;

    vector<pair<string, int>> answersWithTwoBlanks(y);
    for (int i = 0; i < y; i++) {
        string answer;
        int score;
        cin >> answer >> score;
        answersWithTwoBlanks[i] = {answer, score};
    }

    int maxScore = 0;
    for (int i = 0; i <= D; i++) {
        for (int j = 0; j <= D - i; j++) {
            int score = 0;
            int Dcount = i + j;

            // Calculate score for answers with one blank
            for (auto ans : answersWithOneBlank) {
                if (ans.first == 'D' && Dcount > 0) {
                    score += ans.second;
                    Dcount--;
                }
            }

            // Calculate score for answers with two blanks
            for (auto ans : answersWithTwoBlanks) {
                if ((ans.first[0] == 'D' && i > 0) || (ans.first[1] == 'D' && j > 0)) {
                    score += ans.second;
                }
            }

            maxScore = max(maxScore, score);
        }
    }

    cout << maxScore << endl;

    return 0;
}