#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            a[i] = b[j] - b[i];
        }
    }

    vector<int> actual(n, 0);
    for(int i = 0; i < n; i++) {
        actual[i] = a[0];
        for(int j = 0; j < i; j++) {
            actual[i] += a[j];
        }
    }

    bool valid = true;
    for(int i = 0; i < n; i++) {
        if(actual[i] != b[i]) {
            valid = false;
            break;
        }
    }

    if(valid) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}