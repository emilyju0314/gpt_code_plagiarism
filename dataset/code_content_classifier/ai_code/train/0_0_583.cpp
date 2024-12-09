#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    bool possible = true;
    for (int i = 0; i < N-1; i++) {
        if (a[i] % 2 == 1 && a[i+1] % 2 == 1) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}