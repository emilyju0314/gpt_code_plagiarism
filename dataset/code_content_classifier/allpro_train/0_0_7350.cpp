#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Passenger {
    int from;
    int to;
};

bool compare(Passenger p1, Passenger p2) {
    return p1.from < p2.from;
}

int main() {
    int n;
    cin >> n;

    vector<Passenger> passengers(n);
    for (int i = 0; i < n; i++) {
        cin >> passengers[i].from >> passengers[i].to;
    }

    sort(passengers.begin(), passengers.end(), compare);

    int seats_policy1 = 1, max_end = passengers[0].to;
    for (int i = 1; i < n; i++) {
        if (passengers[i].from > max_end) {
            seats_policy1++;
            max_end = passengers[i].to;
        }
    }

    int seats_policy2 = 1, current_end = passengers[0].to;
    for (int i = 1; i < n; i++) {
        if (passengers[i].from > current_end) {
            current_end = passengers[i].to;
        } else if (passengers[i].to < current_end) {
            current_end = passengers[i].to;
        }
    }

    cout << seats_policy1 << " " << seats_policy2 << endl;

    return 0;
}