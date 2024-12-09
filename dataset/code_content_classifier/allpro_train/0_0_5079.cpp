#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    string b_str;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> b_str;

    for(int i = 0; i < n; i++) {
        b[i] = b_str[i] - '0';
    }

    int l = -109, r = 109;

    while(b[n - 1] == 0) {
        n--;
    }

    for(int i = 4; i < n; i++) {
        if(b[i] == 0 && b[i - 1] == 1 && b[i - 2] == 1 && b[i - 3] == 1 && b[i - 4] == 1) {
            l = max(l, max(a[i] + 1, max(a[i - 1] + 1, max(a[i - 2] + 1, max(a[i - 3] + 1, a[i - 4] + 1))));
        } else if(b[i] == 1 && b[i - 1] == 0 && b[i - 2] == 0 && b[i - 3] == 0 && b[i - 4] == 0) {
            r = min(r, min(a[i] - 1, min(a[i - 1] - 1, min(a[i - 2] - 1, min(a[i - 3] - 1, a[i - 4] - 1))));
        }
    }

    cout << l << " " << r << endl;

    return 0;
}