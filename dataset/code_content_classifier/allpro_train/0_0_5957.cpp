#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Participant {
    int id;
    int score;
};

int main() {
    int m;
    while (cin >> m) {
        if (m == 0) break;

        vector<Participant> participants(m);

        for (int i = 0; i < m; i++) {
            participants[i].score = 0;
            cin >> participants[i].id;

            int pins[22];
            for (int j = 0; j < 21; j++) {
                cin >> pins[j];
            }

            int frame = 1;
            int score = 0;
            for (int j = 0; j < 21; j += 2) {
                if (frame == 10) {
                    score += pins[j] + pins[j+1] + pins[j+2];
                } else {
                    if (pins[j] == 10) { // Strike
                        score += 10 + pins[j+2] + pins[j+3];
                        j--;
                    } else if (pins[j] + pins[j+1] == 10) { // Spare
                        score += 10 + pins[j+2];
                    } else {
                        score += pins[j] + pins[j+1];
                    }
                }

                participants[i].score = score;
                if (frame < 10 && (pins[j] == 10 || j == 20)) {
                    frame++;
                } else if (frame == 10 && pins[j] < 10) {
                    break;
                }
            }
        }

        sort(participants.begin(), participants.end(), [](Participant &p1, Participant &p2) {
            if (p1.score == p2.score) {
                return p1.id < p2.id;
            }
            return p1.score > p2.score;
        });

        for (int i = 0; i < m; i++) {
            cout << participants[i].id << " " << participants[i].score << endl;
        }
    }

    return 0;
}