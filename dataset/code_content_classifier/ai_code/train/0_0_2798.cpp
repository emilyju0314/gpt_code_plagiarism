#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Person {
    int t, si, fi, id;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Person> people(n);
    vector<int> arrival_time(n);
    vector<queue<Person>> waiting_up(m + 1);
    vector<queue<Person>> waiting_down(m + 1);
    vector<int> current_floor(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> people[i].t >> people[i].si >> people[i].fi;
        people[i].id = i;
    }

    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.t < b.t;
    });

    int elevator_time = 0;
    int elevator_floor = 1;

    for (int i = 0; i < n; i++) {
        while (elevator_time < people[i].t) {
            int pup = 0, pdown = 0;
            for (int j = elevator_floor + 1; j <= m; j++) {
                pup += waiting_up[j].size();
            }
            for (int j = elevator_floor - 1; j >= 1; j--) {
                pup += waiting_down[j].size();
            }

            if (pup >= pdown) {
                elevator_floor++;
            } else {
                elevator_floor--;
            }
            elevator_time++;
        }

        if (elevator_floor == people[i].si) {
            arrival_time[people[i].id] = elevator_time;
        } else {
            if (elevator_floor < people[i].si) {
                waiting_up[people[i].si].push(people[i]);
            } else {
                waiting_down[people[i].si].push(people[i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arrival_time[i] << endl;
    }

    return 0;
}