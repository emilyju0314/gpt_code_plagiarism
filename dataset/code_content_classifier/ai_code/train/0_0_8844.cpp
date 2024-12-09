#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canBeArranged(vector<string>& words) {
    unordered_map<char, vector<string>> adjList;
    unordered_map<char, int> inDegree, outDegree;

    for (string& word : words) {
        char start = word[0];
        char end = word[word.size() - 1];
        adjList[start].push_back(word);
        inDegree[end]++;
        outDegree[start]++;
    }

    int startCount = 0, endCount = 0;
    for (auto& entry : adjList) {
        char start = entry.first;
        char end = entry.second[0][entry.second[0].size() - 1];
        if (inDegree[start] == outDegree[start] + 1) {
            startCount++;
        } else if (inDegree[start] + 1 == outDegree[start]) {
            endCount++;
        } else if (inDegree[start] == outDegree[start]) {
            startCount++;
            endCount++;
        }
    }

    return ((startCount == 0 && endCount == 0) || (startCount == 1 && endCount == 1));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        if (canBeArranged(words)) {
            cout << "0" << endl;
        } else {
            int count = 0;
            vector<int> indexes;
            for (int i = 0; i < n; i++) {
                string reversedWord = words[i];
                reverse(reversedWord.begin(), reversedWord.end());

                vector<string> tempWords = words;
                tempWords[i] = reversedWord;
                if (canBeArranged(tempWords)) {
                    count++;
                    indexes.push_back(i + 1);
                }
            }

            if (count == 0) {
                cout << "-1" << endl;
            } else {
                cout << count << endl;
                for (int index : indexes) {
                    cout << index << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}