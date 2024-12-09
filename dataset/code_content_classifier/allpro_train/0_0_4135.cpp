#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> b(N), l(N), u(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i] >> l[i] >> u[i];
    }

    int max_study_hours = 0;
    for (int i = 0; i < N; i++) {
        int min_score_needed = max(0, l[i] * X - b[i]);
        max_study_hours = max(max_study_hours, min_score_needed);
    }

    cout << max_study_hours << endl;

    return 0;
}