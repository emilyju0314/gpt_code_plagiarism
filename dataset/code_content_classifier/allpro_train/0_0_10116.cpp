#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> t(N);
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<double> max_speed;
    max_speed.push_back(0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < t[i] * 2; j++) {
            max_speed.push_back(v[i]);
        }
    }

    int total_time = accumulate(t.begin(), t.end(), 0);
    for (int i = 1; i < total_time * 2; i++) {
        max_speed[i] = min(max_speed[i], max_speed[i-1] + 0.5);
    }

    for (int i = total_time * 2 - 2; i >= 0; i--) {
        max_speed[i] = min(max_speed[i], max_speed[i+1] + 0.5);
    }

    double distance = 0.0;
    for (int i = 0; i < total_time * 2 - 1; i++) {
        distance += (max_speed[i] + max_speed[i+1]) / 4.0;
    }

    cout << fixed << setprecision(15) << distance << endl;

    return 0;
}