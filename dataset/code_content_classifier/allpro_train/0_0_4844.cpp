#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int board[4][4];
vector<pair<string, int>> dictionary;
int maxScore = 0;
int timeLimit;

bool isValid(int x, int y) {
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

void findWords(int x, int y, string currentWord, vector<vector<bool>>& visited, int currentTime, int currentScore) {
    if (currentTime > timeLimit) {
        return;
    }

    currentWord += (char)('A' + board[x][y]);
    
    for (int i = 0; i < dictionary.size(); i++) {
        if (currentWord == dictionary[i].first) {
            maxScore = max(maxScore, currentScore + dictionary[i].second);
        }
    }

    visited[x][y] = true;
    currentTime += currentWord.size();
    currentScore += dictionary[currentWord.size()-1].second;

    if (currentWord.size() == 8) {
        return;
    }

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(newX, newY) && !visited[newX][newY]) {
                findWords(newX, newY, currentWord, visited, currentTime, currentScore);
            }
        }
    }

    visited[x][y] = false;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        int score;
        cin >> word >> score;
        dictionary.push_back(make_pair(word, score));
    }

    for (int i = 0; i < 4; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 4; j++) {
            board[i][j] = line[j] - 'A';
        }
    }

    cin >> timeLimit;

    vector<vector<bool>> visited(4, vector<bool>(4, false));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            findWords(i, j, "", visited, 0, 0);
        }
    }

    cout << maxScore << endl;

    return 0;
}