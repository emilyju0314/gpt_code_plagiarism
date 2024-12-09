#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> events(N);

    for (int i = 0; i < N; i++) {
        cin >> events[i].first >> events[i].second;
    }

    int V;
    cin >> V;

    sort(events.begin(), events.end());

    int maxEventsStartingFromZero = 0;
    int maxEventsChoosingInitialPoint = 0;

    for (int i = 0; i < N; i++) {
        int eventsVisited = 1;
        int time = events[i].second;
        int position = events[i].first;

        for (int j = i + 1; j < N; j++) {
            int timeDiff = abs(events[j].second - time);
            int dist = abs(events[j].first - position);

            if (timeDiff <= dist * V) {
                eventsVisited++;
                time = events[j].second;
                position = events[j].first;
            }
        }

        maxEventsStartingFromZero = max(maxEventsStartingFromZero, eventsVisited);
    }

    for (int i = 0; i < N; i++) {
        int eventsVisited = 1;
        int time = events[i].second;
        int position = events[i].first;

        for (int j = i - 1; j >= 0; j--) {
            int timeDiff = abs(events[j].second - time);
            int dist = abs(events[j].first - position);

            if (timeDiff <= dist * V) {
                eventsVisited++;
                time = events[j].second;
                position = events[j].first;
            }
        }

        maxEventsChoosingInitialPoint = max(maxEventsChoosingInitialPoint, eventsVisited);
    }

    cout << maxEventsStartingFromZero << " " << maxEventsChoosingInitialPoint << endl;

    return 0;
}