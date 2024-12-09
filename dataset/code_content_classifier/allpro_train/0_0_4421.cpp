#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        double C, T;
        cin >> C >> T;

        vector<pair<int, int>> problems;
        for (int i = 0; i < n; i++) {
            int a, p;
            cin >> a >> p;
            problems.push_back({a, p});
        }

        double maxScore = 0;
        sort(problems.begin(), problems.end());

        for (int i = 0; i <= n; i++) {
            double totalTrainingTime = i * 10;
            double totalTime = totalTrainingTime;
            double skill = 1.0;

            for (int j = 0; j < n; j++) {
                int a = problems[j].first;
                int p = problems[j].second;
                double problemTime = a / skill;

                if (totalTime + problemTime > T) {
                    break;
                }

                double episodeTime = 10;
                totalTime += episodeTime;
                skill *= 0.9;
                totalTime += problemTime;
                maxScore = max(maxScore, p);
            }

            for (int j = i-1; j >= 0; j--) {
                totalTrainingTime -= 10;
                double trainingSkill = 1.0 + j * C;
                totalTime = totalTrainingTime;

                for (int k = 0; k < n; k++) {
                    int a = problems[k].first;
                    int p = problems[k].second;
                    double problemTime = a / trainingSkill;

                    if (totalTime + problemTime > T) {
                        break;
                    }

                    double episodeTime = 10;
                    totalTime += episodeTime;
                    trainingSkill *= 0.9;
                    totalTime += problemTime;
                    maxScore = max(maxScore, p);
                }
            }
        }

        cout << fixed << setprecision(0) << maxScore << endl;
    }

    return 0;
}