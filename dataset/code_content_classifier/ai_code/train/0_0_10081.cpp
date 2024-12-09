#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    for(int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    
    int fixedPoints = 0;
    for(int i = 0; i < n; i++) {
        if(permutation[i] == i) {
            fixedPoints++;
        }
    }
    
    bool foundMismatch = false;
    for(int i = 0; i < n; i++) {
        if(permutation[i] != i) {
            if(permutation[permutation[i]] == i && !foundMismatch) {
                foundMismatch = true;
                fixedPoints += 2;
            }
        }
    }
    
    cout << fixedPoints << endl;
    
    return 0;
}