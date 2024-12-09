#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long totalPoints = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 && s[i] == s[i-1]) {
            totalPoints += min(a[i], a[i-1]);
        }
    }

    cout << totalPoints << endl;

    return 0;
}