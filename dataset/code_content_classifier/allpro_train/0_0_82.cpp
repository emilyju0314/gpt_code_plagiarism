#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> &A, int N) {
    int swaps = 0;
    for (int i = 0; i < N-1; i++) {
        int mini = i;
        for (int j = i+1; j < N; j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swaps++;
            swap(A[i], A[mini]);
        }
    }
    cout << A[0];
    for (int i = 1; i < N; i++) {
        cout << " " << A[i];
    }
    cout << endl << swaps << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    selectionSort(A, N);

    return 0;
}