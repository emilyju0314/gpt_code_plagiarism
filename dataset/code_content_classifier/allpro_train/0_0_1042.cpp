#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    
    swap(A[i+1], A[r]);
    
    return i+1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    quickSort(A, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " "; // separate elements by space
        if (i == n-1) cout << "[" << A[i] << "]"; // indicate pivot element with brackets
        else cout << A[i];
    }
    cout << endl;
    
    return 0;
}