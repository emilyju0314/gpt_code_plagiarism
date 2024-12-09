#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i*n + i - n;
    }
    cout << sum << endl;
    
    int x = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == k) cout << sum - (n-j)*n - x;
            else cout << x;
            cout << " ";
            x++;
        }
        cout << endl;
    }
    
    return 0;
}