#include <iostream>
#include <vector>

using namespace std;

int cnt;

void insertionSort(vector<int>& A, int n, int g) {
    for(int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(vector<int>& A, int n) {
    cnt = 0;
    int m = 0;
    vector<int> G;
    int h = 1;
    while(h <= n) {
        G.push_back(h);
        h = 3*h + 1;
        m++;
    }

    cout << m << endl;
    for(int i = m-1; i >= 0; i--) {
        cout << G[i];
        if(i > 0) cout << " ";
    }
    cout << endl;

    for(int i = 0; i < m; i++) {
        insertionSort(A, n, G[i]);
    }

    cout << cnt << endl;
    for(int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    shellSort(A, n);

    return 0;
}