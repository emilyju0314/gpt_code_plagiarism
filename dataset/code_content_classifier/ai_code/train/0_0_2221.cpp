#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string response;

    for (int i = 1; i <= n - 1; i++) {
        cout << "1 " << i << " " << (i + 1) << endl;
        cout.flush();
        cin >> response;
        if (response == "TAK") {
            cout << "2 " << i << " " << (i + 1) << endl;
            cout.flush();
            return 0;
        }
    }

    cout << "1 " << n << " 1" << endl;
    cout.flush();
    cin >> response;
    if (response == "TAK") {
        cout << "2 " << n << " 1" << endl;
        cout.flush();
        return 0;
    }

    return 0;
}