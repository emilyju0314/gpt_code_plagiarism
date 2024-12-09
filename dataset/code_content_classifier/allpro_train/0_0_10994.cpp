#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<int> arrival_times(N);
    for (int i = 0; i < N; i++) {
        cin >> arrival_times[i];
    }

    int max_study_time = 0;
    int previous_arrival_time = 0;

    for (int i = 0; i < N; i++) {
        int current_study_time = arrival_times[i] - previous_arrival_time - 2*M;
        max_study_time = max(max_study_time, current_study_time);
        previous_arrival_time = arrival_times[i];
    }

    int last_study_time = T - previous_arrival_time - M;
    max_study_time = max(max_study_time, last_study_time);

    cout << max_study_time << endl;

    return 0;
}