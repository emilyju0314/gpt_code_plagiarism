#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> heroes;

bool canDefeatAllHeroes(double radius) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double distance = hypot(heroes[i].first - heroes[j].first, heroes[i].second - heroes[j].second);
            if (distance <= radius) {
                count++;
                break;
            }
        }
    }
    return count >= M;
}

int main() {
    cin >> N >> M;
    heroes.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> heroes[i].first >> heroes[i].second;
    }

    double low = 0.0, high = 2e5;
    const double EPS = 1e-6;
    while (high - low > EPS) {
        double mid = (low + high) / 2.0;
        if (canDefeatAllHeroes(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << high << endl;

    return 0;
}