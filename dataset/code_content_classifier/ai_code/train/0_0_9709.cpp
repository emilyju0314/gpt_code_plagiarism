#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Event {
    int time;
    int speed;

    Event(int t, int s) : time(t), speed(s) {}
};

struct CompareEvent {
    bool operator()(Event& e1, Event& e2) {
        return e1.time > e2.time; // prioritize events with earlier time
    }
};

int main() {
    int q;
    cin >> q;

    priority_queue<Event, vector<Event>, CompareEvent> events;
    int v = 0;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int t, s;
            cin >> t >> s;
            events.push(Event(t, s));
        } else if (type == 2) {
            int t;
            cin >> t;
            // Delete event happening at time t (if it exists)
            // This is not necessary as per the problem statement
        } else if (type == 3) {
            int l, r, v;
            cin >> l >> r >> v;
            double burst_time = -1;
            int current_time = 1;
            int current_speed = 0;
            int remaining_patience = v;
            while (current_time <= r) {
                // Update tap speed with events occurring at current time
                while (!events.empty() && events.top().time <= current_time) {
                    current_speed = events.top().speed;
                    events.pop();
                }
                remaining_patience += current_speed;
                if (remaining_patience <= 0) {
                    double time_to_burst = current_time - 1 + (double)v / (double)(-current_speed);
                    burst_time = (burst_time == -1) ? time_to_burst : min(burst_time, time_to_burst);
                    break;
                }
                current_time++;
            }

            if (burst_time == -1) {
                cout << -1 << endl;
            } else {
                cout << setprecision(10) << fixed << burst_time << endl;
            }
        }
    }

    return 0;
}