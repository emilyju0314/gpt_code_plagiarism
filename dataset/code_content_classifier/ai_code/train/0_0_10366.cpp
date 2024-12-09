#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> likes(n);
    for (int i = 0; i < n; i++) {
        cin >> likes[i];
    }
    
    for (int i = 0; i < n; i++) {
        int a = i;
        int b = likes[a] - 1;
        int c = likes[b] - 1;
        if (a == likes[c] - 1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}