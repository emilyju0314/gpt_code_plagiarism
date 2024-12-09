#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    // Calculate the time needed to read X books from desk A
    int time_needed = 0;
    int max_books_read = 0;
    int j = M;

    for (int i = 0; i <= N; i++) {
        // Calculate the time needed to read X books from desk A
        time_needed += A[i];
        
        // Check if we have enough time to read the remaining books from desk B
        while (j > 0 && time_needed > K) {
            j--;
            time_needed -= B[j];
        }
        
        if (time_needed <= K) {
            max_books_read = max(max_books_read, i + j);
        }
    }

    cout << max_books_read << endl;

    return 0;
}