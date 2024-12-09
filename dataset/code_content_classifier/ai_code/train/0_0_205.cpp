#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        if (num == "?") {
            a[i] = 0;
        } else {
            a[i] = stoi(num);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                if (i - j >= 0) {
                    sum += a[i - j];
                }
            }
            for (int j = 0; j < k; j++) {
                if (i + j < n) {
                    a[i + j] = sum;
                    sum -= a[i - j];
                    if (i + j + 1 < n) {
                        sum += a[i + j + 1];
                    }
                }
            }
        }
    }
    
    for (int i = 1; i < n - k + 1; i++) {
        if (a[i - 1] >= a[i]) {
            cout << "Incorrect sequence" << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}