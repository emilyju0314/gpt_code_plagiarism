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

    int count = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            if(i > 0 && i < n-1 && a[i-1] != -1 && a[i+1] != -1) {
                if(a[i+1] - a[i-1] != a[i+1] / a[i-1]) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}