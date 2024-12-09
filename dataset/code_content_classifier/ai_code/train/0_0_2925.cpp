#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long int total_votes = 1; // Initial total votes
    long long int Takahashi_votes = 1; // Initial votes for Takahashi
    long long int Aoki_votes = 1; // Initial votes for Aoki

    for (int i = 0; i < N; i++) {
        long long int T, A;
        cin >> T >> A;

        long long int ratio = max((T + Takahashi_votes - 1) / T, (A + Aoki_votes - 1) / A);
        
        Takahashi_votes = T * ratio;
        Aoki_votes = A * ratio;

        total_votes = max(Takahashi_votes, Aoki_votes);
    }

    cout << total_votes << endl;

    return 0;
}