#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> p[i];
    }
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> operations;
    int i = N-1;
    while (i > 0) {
        operations.push_back(i);
        i = p[i-1];
    }
    
    cout << operations.size() << endl;
    for (int i = operations.size()-1; i >= 0; i--) {
        cout << operations[i] + 1 << endl;
    }
    
    return 0;
}