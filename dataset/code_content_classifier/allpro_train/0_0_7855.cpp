#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int currentTown = 1;
    vector<bool> visited(N+1, false);
    
    while (K > 0 && !visited[currentTown]) {
        visited[currentTown] = true;
        currentTown = A[currentTown - 1];
        K--;
    }

    if (K == 0) {
        cout << currentTown << endl;
    } else {
        int loopStartTown = currentTown;
        int loopLength = 1;
        currentTown = A[currentTown - 1];
    
        while (currentTown != loopStartTown) {
            loopLength++;
            currentTown = A[currentTown - 1];
        }

        K %= loopLength;
        currentTown = 1;
        while (K > 0) {
            currentTown = A[currentTown - 1];
            K--;
        }

        cout << currentTown << endl;
    }

    return 0;
}