#include <iostream>
#include <string>

using namespace std;

int minChanges(string a, string b) {
    int n = a.length();
    int m = b.length();
    
    int numChanges = 0;
    for (int i = 0; i <= n - m; i++) {
        int tmpChanges = 0;
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                tmpChanges++;
            }
        }
        numChanges += (tmpChanges == 0) ? 1 : 0;
    }
    
    return numChanges;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    for (int k = 0; k <= n - m + 1; k++) {
        cout << minChanges(a, b) << " ";
        a = "0" + a;
        if (a.length() > n) {
            break;
        }
    }
    
    for (int i = 0; i < n - m + 2 - (n - m + 1); i++) {
        cout << "-1 ";
    }
    
    return 0;
}