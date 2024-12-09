#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // Check if a graph satisfying the conditions exists
    for (int i = 0; i < N; i++) {
        int total_edges = A[i] + B[i];
        if (total_edges > N-1 || total_edges < i) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Calculate the minimum possible number of edges in the graph
    int min_edges = 0;
    for (int i = 0; i < N; i++) {
        min_edges = max(min_edges, i + max(A[i], B[i]));
    }

    cout << min_edges + 1 << endl;

    return 0;
}