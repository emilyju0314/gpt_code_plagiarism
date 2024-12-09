#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> scores(n);

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        scores[i] = make_pair(a, make_pair(b, c));
    }

    int myScore = 0;

    for (int i = 0; i < n; ++i) {
        int score = 0;

        for (int j = 0; j < 3; ++j) {
            int minutes = scores[i].first;
            if (minutes > 0) {
                if (j == 0) {
                    if (scores[i].second.first > 0 && abs(scores[i].second.first) > minutes) {
                        score += 250 + scores[i].second.first;
                    } else {
                        score += 500;
                    }
                } else if (j == 1) {
                    if (scores[i].second.second > 0 && abs(scores[i].second.second) > minutes) {
                        score += 250 + scores[i].second.second;
                    } else {
                        score += 1000;
                    }
                } else {
                    if (scores[i].second.second > 0 && abs(scores[i].second.second) > minutes) {
                        score += 250 + scores[i].second.second;
                    } else {
                        score += 1500;
                    }
                }
            }
        }

        myScore = max(myScore, score);
    }

    int numGreater = 0;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        
        for (int j = 0; j < 3; ++j) {
            int minutes = scores[i].first;
            if (minutes > 0) {
                if (j == 0) {
                    if (scores[i].second.first > 0 && abs(scores[i].second.first) > minutes) {
                        score += 250 + scores[i].second.first;
                    } else {
                        score += 500;
                    }
                } else if (j == 1) {
                    if (scores[i].second.second > 0 && abs(scores[i].second.second) > minutes) {
                        score += 250 + scores[i].second.second;
                    } else {
                        score += 1000;
                    }
                } else {
                    if (scores[i].second.second > 0 && abs(scores[i].second.second) > minutes) {
                        score += 250 + scores[i].second.second;
                    } else {
                        score += 1500;
                    }
                }
            }
        }

        if (score > myScore) {
            numGreater++;
        }
    }

    cout << numGreater + 1 << endl;

    return 0;
}