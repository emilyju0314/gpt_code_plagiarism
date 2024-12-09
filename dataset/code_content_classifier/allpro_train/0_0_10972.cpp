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

    long long total_comfort = 0;
    long long max_comfort = 0;
    
    // Calculate comfort when cutting at each position
    for (int i = 1; i < N; i++) {
        total_comfort += abs(A[i] - A[i-1]);
    }
    
    // Calculate maximum total comfort by rotating the circle
    for (int i = 1; i < N; i++) {
        max_comfort = max(max_comfort, total_comfort - abs(A[i] - A[i-1]) - abs(A[i] - A[(i+1)%N]) + abs(A[i-1] - A[(i+1)%N]));
    }

    cout << max_comfort << endl;

    return 0;
}