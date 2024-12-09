#include <iostream>
#include <vector>

int merge(std::vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<int> L(n1+1);
    std::vector<int> R(n2+1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    int comparisons = 0;
    for (int k = left; k < right; k++) {
        comparisons++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return comparisons;
}

void mergeSort(std::vector<int>& A, int left, int right, int& total_comparisons) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid, total_comparisons);
        mergeSort(A, mid, right, total_comparisons);
        total_comparisons += merge(A, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int total_comparisons = 0;
    mergeSort(A, 0, n, total_comparisons);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    std::cout << total_comparisons << std::endl;

    return 0;
}