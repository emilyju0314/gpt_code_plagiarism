#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Event {
    int time;
    char person;
};

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<Event> events(n+1);
    for (int i = 0; i < n; i++) {
        cin >> events[i].time >> events[i].person;
    }
    cin >> events[n].time;
    events[n].person = 'X'; // Denotes the tea time

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.time < b.time;
    });

    map<char, queue<int>> letters;
    int cost = 0;

    for (int i = 0; i < n+1; i++) {
        if (events[i].person == 'W' || events[i].person == 'P') {
            char currentPerson = events[i].person;
            int currentTime = events[i].time;

            if (!letters[currentPerson].empty() && letters[currentPerson].front() <= currentTime) {
                letters[currentPerson].pop();
            } else {
                if (!letters['X'].empty() && letters['X'].front() <= currentTime) {
                    letters['X'].pop();
                } else {
                    letters['X'].push(currentTime);
                    cost += c;
                }
                letters[currentPerson].pop();
            }
        } else { // Tea time
            while (!letters['W'].empty()) {
                cost += d;
                letters['W'].pop();
            }
            while (!letters['P'].empty()) {
                cost += d;
                letters['P'].pop();
            }
        }
    }

    cout << cost << endl;

    return 0;
}