#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        vector<string> events;
        string event;
        while (cin >> event) {
            if (event == "HIT" || event == "HOMERUN" || event == "OUT") {
                events.push_back(event);
            }

            if (events.size() == 3) {
                int score = 0;
                int runnersOnBase = 0;

                for (string e : events) {
                    if (e == "HIT") {
                        runnersOnBase++;
                        if (runnersOnBase == 4) {
                            score++;
                            runnersOnBase = 3;
                        }
                    } else if (e == "HOMERUN") {
                        score += runnersOnBase + 1;
                        runnersOnBase = 0;
                    } else {
                        // OUT event, do nothing
                    }
                }

                cout << score << endl;
                break;
            }
        }
    }

    return 0;
}