#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A) {
    for (int i = 1; i < A.size(); i++) {
        int key = A[i];
        int j = i - 1;
        
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        
        A[j + 1] = key;
        
        for (int k = 0; k < A.size(); k++) {
            cout << A[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    insertionSort(A);
    
    return 0;
}