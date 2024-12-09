#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long merge(vector<int>& A, int left, int mid, int right) {
    int i = left, j = mid, k = 0;
    vector<int> temp(right - left);
    long long inv_count = 0;
    
    while (i < mid && j < right) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            inv_count += mid - i;
        }
    }
    
    while (i < mid) {
        temp[k++] = A[i++];
    }
    while (j < right) {
        temp[k++] = A[j++];
    }
    
    for (i = left, k = 0; i < right; i++, k++) {
        A[i] = temp[k];
    }
    
    return inv_count;
}

long long mergeSort(vector<int>& A, int left, int right) {
    if (right - left <= 1) {
        return 0;
    }
    
    int mid = left + (right - left) / 2;
    
    long long inv_count = 0;
    inv_count += mergeSort(A, left, mid);
    inv_count += mergeSort(A, mid, right);
    inv_count += merge(A, left, mid, right);
    
    return inv_count;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> B(N * K);
    
    for (int i = 0; i < N * K; i++) {
        B[i] = A[i % N];
    }
    
    long long inversions = mergeSort(B, 0, N * K) % MOD;
    
    cout << inversions << endl;
    
    return 0;
}