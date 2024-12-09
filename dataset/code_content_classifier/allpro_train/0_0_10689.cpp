#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int currentChild = 0;
    while (n > 0) {
        if (a[currentChild] <= m) {
            n--;
        } else {
            a[currentChild] -= m;
        }
        currentChild = (currentChild + 1) % n;
    }
    
    cout << currentChild + 1 << endl;
    
    return 0;
}