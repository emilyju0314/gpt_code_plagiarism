#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int friends[n];
    for (int i = 0; i < n; i++) {
        cin >> friends[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << friends[i] << " ";
    }
    
    return 0;
}