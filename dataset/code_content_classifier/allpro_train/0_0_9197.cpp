#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[0]) {
            index = i;
            break;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[(index + i) % n] == b[i]) {
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}