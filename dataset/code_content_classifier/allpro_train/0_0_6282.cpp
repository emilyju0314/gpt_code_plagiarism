#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Racer {
    string name;
    int points;
};

bool compareRacers(const Racer& r1, const Racer& r2) {
    if (r1.points == r2.points) {
        return r1.name < r2.name;
    }
    return r1.points > r2.points;
}

int main() {
    int n;
    cin >> n;

    vector<Racer> racers(n);
    for (int i = 0; i < n; i++) {
        cin >> racers[i].name >> racers[i].points;
    }

    int m;
    cin >> m;

    vector<int> points(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }

    string Vasya;
    cin >> Vasya;

    sort(racers.begin(), racers.end(), compareRacers);

    int VasyaIndex = 0;
    int rankings = 0;
    int samePoints = 0;
    for (int i = 0; i < n; i++) {
        if (racers[i].name == Vasya) {
            VasyaIndex = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (racers[i].points == racers[VasyaIndex].points) {
            samePoints++;
        } else {
            rankings++;
        }
    }

    int highestPlace = rankings + samePoints;
    int lowestPlace = max(1, rankings + 1);

    cout << highestPlace << " " << lowestPlace << endl;

    return 0;
}