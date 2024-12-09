#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    int Q = 0;
    for (int i = 0; i < n; i++) {
        Q ^= p[i];
    }
    
    cout << Q << endl;
    
    return 0;
}