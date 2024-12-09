#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int current = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(i > 0 && a[i-1] == current)
                current = (current % n) + 1; // Adjust current to avoid repeating adjacent elements
            a[i] = current;
            current = (current % n) + 1;
        }
        cout << a[i] << " ";
    }

    return 0;
}