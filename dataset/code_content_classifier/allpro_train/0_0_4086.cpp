#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string s = "";
        for(int i = 0; i < n; i++) {
            s += 'a' + i % b;
        }

        cout << s << endl;
    }

    return 0;
}