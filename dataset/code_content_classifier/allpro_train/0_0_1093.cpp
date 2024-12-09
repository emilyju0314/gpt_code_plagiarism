#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> crushes(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> crushes[i];
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int count = 1;
        int next = crushes[i];
        while (next != i && count <= n) {
            next = crushes[next];
            count++;
        }
        
        if (next == i) {
            if (ans == -1) {
                ans = count;
            } else {
                ans = gcd(ans, count);
            }
        }
    }

    cout << ans << endl;

    return 0;
}