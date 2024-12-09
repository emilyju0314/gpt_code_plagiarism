#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int drives[n];
    for(int i = 0; i < n; i++) {
        cin >> drives[i];
    }
    
    sort(drives, drives + n, greater<int>());
    
    int num_drives = 0;
    int space_left = m;
    
    for(int i = 0; i < n; i++) {
        if(space_left <= 0) {
            break;
        }
        num_drives++;
        space_left -= drives[i];
    }
    
    cout << num_drives << endl;
    
    return 0;
}