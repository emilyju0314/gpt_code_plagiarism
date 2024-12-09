#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> password(n);

    for(int i=0; i<n; i++) {
        cout << "? 1 " << i+1 << endl;
        cout.flush();

        cin >> password[i];
    }

    cout << "! ";
    for(int i=0; i<n; i++) {
        int result = 0;
        for(int j=0; j<n; j++) {
            if(i != j) {
                result |= password[j];
            }
        }
        cout << result << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}