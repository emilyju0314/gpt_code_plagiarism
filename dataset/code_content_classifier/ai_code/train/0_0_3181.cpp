#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;

    if (B >= C) {
        cout << "0" << endl;
    } else {
        ans += B;
        
        C -= B;
        
        if (A >= C) {
            ans += C;
        } else {
            ans += A + 1;
        }

        cout << ans << endl;
    }

    return 0;
}