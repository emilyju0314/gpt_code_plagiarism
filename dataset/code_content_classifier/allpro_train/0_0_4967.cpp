#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    sort(s.begin(), s.end());

    int x = *s.rbegin();
    int y = *s.begin();
    while(true) {
        if(s.find(x - y) == s.end()) {
            s.insert(x - y);
            x = y;
            y = x - y;
        } else if(s.find(x - y) == s.find(x) || s.find(x - y) == s.find(y)) {
            cout << "Alice" << endl;
            break;
        } else {
            cout << "Bob" << endl;
            break;
        }
    }

    return 0;
}