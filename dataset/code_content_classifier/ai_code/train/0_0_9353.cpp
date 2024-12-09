#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_jobs = 0;
    for (int i = 1; i <= 100; i++) {
        int total_jobs = 0;
        for (int j = 0; j < N; j++) {
            total_jobs += min(i, A[j]);
        }
        max_jobs = max(max_jobs, total_jobs);
    }

    cout << max_jobs << endl;

    return 0;
}