#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, int> wordMap;
    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        wordMap[words[i]] = i;
    }

    vector<vector<int>> pairs(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        pairs[X-1][Y-1] = 1;
    }

    int maxPalindromeLength = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (pairs[i][j] && pairs[j][k]) {
                    maxPalindromeLength = max(maxPalindromeLength, (int)words[i].size() + (int)words[j].size() + (int)words[k].size());
                }
            }
        }
    }

    if (maxPalindromeLength > 0) {
        cout << maxPalindromeLength << endl;
    } else {
        cout << (M > 0 ? 0 : -1) << endl;
    }

    return 0;
}