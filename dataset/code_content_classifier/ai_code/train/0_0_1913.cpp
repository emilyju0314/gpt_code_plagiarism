#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_val = a[0];
    int min_val = a[0];
    
    for(int i = 0; i < n; i++) {
        if(a[i] > max_val) {
            max_val = a[i];
        }
        if(a[i] < min_val) {
            min_val = a[i];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != max_val && a[i] != min_val) {
            sum += a[i];
        }
    }

    cout << sum << endl;

    return 0;
}