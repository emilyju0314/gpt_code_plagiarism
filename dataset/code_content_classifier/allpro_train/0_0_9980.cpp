#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int zeros, int ones, int qMarks) {
    if (zeros + qMarks >= ones && ones + qMarks >= zeros) {
        return true;
    }
    return false;
}

void generateOutcomes(string cards) {
    int zeros = 0, ones = 0, qMarks = 0;

    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == '0') {
            zeros++;
        } else if (cards[i] == '1') {
            ones++;
        } else {
            qMarks++;
        }
    }

    vector<string> results;

    if (isPossible(zeros, ones, qMarks - 2)) {
        results.push_back("00");
    }
    if (isPossible(zeros + 1, ones, qMarks - 1)) {
        results.push_back("01");
    }
    if (isPossible(zeros, ones + 1, qMarks - 1)) {
        results.push_back("10");
    }
    if (isPossible(zeros + 2, ones, qMarks - 2)) {
        results.push_back("11");
    }

    sort(results.begin(), results.end());

    for (string result : results) {
        cout << result << endl;
    }
}

int main() {
    string cards;
    cin >> cards;

    generateOutcomes(cards);

    return 0;
}