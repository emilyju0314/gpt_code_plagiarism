#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& A, int N) {
    int swaps = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                swaps++;
            }
        }
    }
    
    cout << "Sorted sequence:" << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Number of swaps: " << swaps << endl;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    BubbleSort(A, N);
    
    return 0;
}