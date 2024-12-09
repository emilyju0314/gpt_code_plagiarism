#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    
    vector<int> a(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i * N + j] = i + 1;
        }
    }
    
    vector<int> b(N * N);
    for (int i = 0; i < N; i++) {
        b[x[i] - 1] = i + 1;
    }
    
    for (int i = 0; i < N * N; i++) {
        if (a[i] != b[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    for (int i = 0; i < N * N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}