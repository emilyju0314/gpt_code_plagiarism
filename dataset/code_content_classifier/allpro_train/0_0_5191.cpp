#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    cout << a[0] << "/" << b[1] << endl;
    
    return 0;
} 

//Input
//2 1
//1 2
//1 2 1 1

//Output
//1/2