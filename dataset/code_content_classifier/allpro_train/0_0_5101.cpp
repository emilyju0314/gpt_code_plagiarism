#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int findCommonSentences(int n, int m, vector<pair<int, int>> cuts, vector<string> pieces) {
    unordered_map<string, int> sentenceCount;

    // Generate all possible sentences
    for (int i = 0; i < m; i++) {
        string sentence = "";
        int currentCut = 0;

        for (int j = 0; j < pieces[i].size(); j++) {
            sentence += pieces[i][j];
            while (currentCut < cuts.size() && cuts[currentCut].second <= j) {
                currentCut++;
            }
            if (currentCut < cuts.size() && cuts[currentCut].first == j) {
                sentence += cuts[currentCut].second;
            }
        }

        sentenceCount[sentence]++;
    }
    // Count common sentences
    int commonSentences = 0;
    for (int i = 0; i < m; i++) {
        string sentence = "";
        int currentCut = 0;

        for (int j = 0; j < pieces[i].size(); j++) {
            sentence += pieces[i][j];
            while (currentCut < cuts.size() && cuts[currentCut].second <= j) {
                currentCut++;
            }
            if (currentCut < cuts.size() && cuts[currentCut].first == j) {
                sentence += cuts[currentCut].second;
            }
        }

        if (sentenceCount[sentence] == 2) {
            commonSentences++;
            sentenceCount[sentence] = 0;
        }
    }

    return commonSentences;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> cuts;
        vector<string> pieces;

        for (int i = 0; i < m; i++) {
            int a, b;
            string s;
            cin >> a >> b >> s;
            cuts.push_back({a, b});
            pieces.push_back(s);
        }

        int result = findCommonSentences(n, m, cuts, pieces);
        cout << result % MOD << endl;
    }

    return 0;
}