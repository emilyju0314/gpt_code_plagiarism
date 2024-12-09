#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string path1, path2;
    cin >> path1 >> path2;
    
    for (int i = 0; i < n - 1; i++) {
        if ((path1[i] == 'N' && path2[i] != 'S') || 
            (path1[i] == 'S' && path2[i] != 'N') ||
            (path1[i] == 'E' && path2[i] != 'W') ||
            (path1[i] == 'W' && path2[i] != 'E')) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}