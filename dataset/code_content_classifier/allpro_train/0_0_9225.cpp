#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        string a = to_string(i);
        string ar = string(a.rbegin(), a.rend());
        if(stoi(a) + stoi(ar) == stoi(n)) {
            ans = stoi(a);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}