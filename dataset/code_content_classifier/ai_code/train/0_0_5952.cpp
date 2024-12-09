#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N), b(N);
    
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    
    for(int i = 0; i < N; i++) {
        if(a[i] < b[i]) {
            cout << "No" << endl;
            return 0;
        }
        int diff = a[i] - b[i];
        if(i < N-1) {
            a[i+1] += 2*diff;
        }
    }
    
    if(a[N-1] >= b[N-1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}