#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> columns(n);
    for(int i = 0; i < n; i++) {
        cin >> columns[i];
    }
    
    int nonOverlappingDominos = 0;
    for(int i = 0; i < n; i++) {
        nonOverlappingDominos += columns[i] / 2;
        if(columns[i] % 2 != 0 && i < n-1) {
            nonOverlappingDominos += columns[i+1] / 2;
            columns[i+1] = (columns[i+1] % 2 == 0) ? 0 : 1;
        }
    }
    
    cout << nonOverlappingDominos << endl;
    
    return 0;
}