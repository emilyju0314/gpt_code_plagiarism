#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> marks(k);
    unordered_set<int> rememberedScores;

    for (int i = 0; i < k; i++) {
        cin >> marks[i];
    }

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        rememberedScores.insert(score);
    }

    unordered_set<int> possibleScores;
    for (int i = 0; i < k; i++) {
        int currentScore = 0;
        for (int j = 0; j < k; j++) {
            currentScore += marks[j];
            if (rememberedScores.find(currentScore) != rememberedScores.end()) {
                possibleScores.insert(currentScore);
            }
        }
    }

    cout << possibleScores.size() << endl;

    return 0;
}