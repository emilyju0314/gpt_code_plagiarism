#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> oddArr, evenArr;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            evenArr.push_back(a[i]);
        } else {
            oddArr.push_back(a[i]);
        }
    }

    if(oddArr.size() < k - p || (k - p) % 2 != oddArr.size() % 2) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    for(int i = 0; i < p; i++) {
        cout << "1 " << evenArr[i] << endl;
    }

    for(int i = 0; i < k - p; i++) {
        cout << "1 " << oddArr[i] << endl;
    }

    for(int i = p; i < evenArr.size(); i++) {
        cout << "1 " << evenArr[i] << endl;
    }

    for(int i = k - p; i < oddArr.size(); i++) {
        cout << "1 " << oddArr[i] << endl;
    }

    return 0;
}