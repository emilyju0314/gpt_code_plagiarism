#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bus {
    int start;
    int end;
    int time;

    Bus(int s, int e, int t) : start(s), end(e), time(t) {}
};

struct Citizen {
    int start;
    int end;
    int time;
    int index;

    Citizen(int s, int e, int t, int i) : start(s), end(e), time(t), index(i) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Bus> buses;
    vector<Citizen> citizens;
    vector<int> result(m, -1);

    for (int i = 0; i < n; i++) {
        int s, f, t;
        cin >> s >> f >> t;
        buses.push_back(Bus(s, f, t));
    }

    for (int i = 0; i < m; i++) {
        int l, r, b;
        cin >> l >> r >> b;
        citizens.push_back(Citizen(l, r, b, i));
    }

    sort(buses.begin(), buses.end(), [](const Bus &a, const Bus &b) {
        return a.time < b.time;
    });

    for (const auto &citizen : citizens) {
        for (int j = 0; j < buses.size(); j++) {
            if (buses[j].start <= citizen.start && buses[j].end >= citizen.end && buses[j].time >= citizen.time) {
                result[citizen.index] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << result[i] << " ";
    }

    return 0;
}