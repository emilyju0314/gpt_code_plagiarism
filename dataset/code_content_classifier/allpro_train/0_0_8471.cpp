#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    
    vector<int> a(N), b(N);
    a[0] = 1;
    b[0] = 1000000000;
    
    for (int i = 1; i < N; i++) {
        a[i] = a[i-1] + 1;
        b[i] = 1000000000 - i + 1;
    }
    
    for (int i = 0; i < N; i++) {
        cout << a[p[i]-1] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < N; i++) {
        cout << b[p[i]-1] << " ";
    }
    cout << endl;
    
    return 0;
}