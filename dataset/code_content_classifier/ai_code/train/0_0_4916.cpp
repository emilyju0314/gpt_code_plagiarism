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

    // Function to calculate minimum number of subarrays needed
    int count = 1;
    for (int i = 1; i < N-1; i++) {
        if ((A[i-1] < A[i] && A[i] > A[i+1]) || (A[i-1] > A[i] && A[i] < A[i+1])) {
            count++;
            while (i < N-1 && A[i] == A[i+1]) {
                i++;
            }
        }
    }

    cout << count << endl;

    return 0;
}