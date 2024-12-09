#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> difficulties(n);
    for(int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    int ans = 1;
    int length = 1;
    for(int i = 0; i < n - 1; i++) {
        if(difficulties[i+1] <= 2 * difficulties[i]) {
            length++;
        } else {
            ans = max(ans, length);
            length = 1;
        }
    }
    ans = max(ans, length);

    cout << ans << endl;

    return 0;
}