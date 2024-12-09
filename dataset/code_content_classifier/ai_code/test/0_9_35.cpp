#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    string b;
    cin >> b;

    int count = 0;
    for(int i=0; i<n; i++) {
        int x = a[i];
        for(int j=i; j<n; j++) {
            if(b[j] == '*') {
                x *= a[j+1];
            } else {
                x /= a[j+1];
            }
            if(x == (int)x) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}