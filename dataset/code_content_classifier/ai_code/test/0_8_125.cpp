#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int last = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(i == 0) {
                int k = 1;
                while(k == last || (i + 1 < n && a[i+1] == k)) {
                    k++;
                }
                a[i] = k;
            } else {
                a[i] = a[i-1];
            }
        } else {
            last = a[i];
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}