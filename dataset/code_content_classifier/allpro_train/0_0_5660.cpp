#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int maxNum = *max_element(s.begin(), s.end());
    int secondMax = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] != maxNum && (secondMax == -1 || s[i] > secondMax)) {
            secondMax = s[i];
        }
    }

    int maxLucky = maxNum ^ secondMax;
    cout << maxLucky << endl;

    return 0;
}