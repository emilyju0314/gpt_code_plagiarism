#include <iostream>
#include <vector>

long long merge(std::vector<int>& a, int start, int mid, int end) {
    int i = start, j = mid + 1;
    std::vector<int> temp;
    long long inversions = 0;

    while(i <= mid && j <= end) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            inversions += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(a[j]);
        j++;
    }

    for(int k = start; k <= end; k++) {
        a[k] = temp[k - start];
    }

    return inversions;
}

long long mergeSort(std::vector<int>& a, int start, int end) {
    if(start >= end) {
        return 0;
    }

    int mid = (start + end) / 2;
    long long inversions = 0;

    inversions += mergeSort(a, start, mid);
    inversions += mergeSort(a, mid + 1, end);
    inversions += merge(a, start, mid, end);

    return inversions;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(n);
        std::vector<int> b(m);

        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for(int i = 0; i < m; i++) {
            std::cin >> b[i];
        }

        std::vector<int> c(n + m);

        for(int i = 0; i < n + m; i++) {
            if(i < n) {
                c[i] = a[i];
            } else {
                c[i] = b[i - n];
            }
        }

        long long result = mergeSort(c, 0, n + m - 1);
        std::cout << result << std::endl;
    }

    return 0;
}