#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

class Event {
public:
    int time;
    int speed;

    Event(int t, int s) : time(t), speed(s) {}
};

int main() {
    int q;
    cin >> q;

    priority_queue<Event*, vector<Event*>, function<bool(Event*, Event*)>> events([](Event* a, Event* b) {
        return a->time > b->time;
    });

    events.push(new Event(1, 0)); // Initial event at time 1 with speed 0
    long double v = 0;
    long double t0 = 1;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int t, s;
            cin >> t >> s;
            events.push(new Event(t, s));
        } else if (type == 2) {
            int t;
            cin >> t;
            while (events.top()->time == t) {
                events.pop();
            }
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            long double burst_time = -1;
            long double curr_v = v;

            while (!events.empty() && events.top()->time <= r) {
                Event* e = events.top();
                events.pop();

                long double delta_t = e->time - t0;
                t0 = e->time;
                curr_v -= delta_t * v; // Adjust patience volume

                if (curr_v <= 0) {
                    burst_time = e->time + curr_v / v;
                    break;
                }

                v += e->speed;
            }

            if (burst_time == -1) {
                burst_time = r;
            }

            cout << fixed << setprecision(10) << burst_time << endl;
            v = 0; // Reset speed for the next query
            while (!events.empty()) {
                events.pop();
            }
        }
    }

    return 0;
}