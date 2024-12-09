#include <iostream>
#include <string>
#include <vector>

using namespace std;

int query(int i, string y) {
    cout << i << " " << y << endl;
    string response;
    cin >> response;
    if (response == "yes") return 1;
    else return 0;
}

int main() {
    int n, b;
    cin >> n >> b;

    string y = "";
    for (int i = 0; i < b; i++) y += "0";

    int max_num = 0;

    for (int i = 1; i <= n; i++) {
        string current = y;
        current[b - 1] = '1';
        if (query(i, current)) {
            max_num |= 1 << (b-1);
        } else {
            for (int j = b - 2; j >= 0; j--) {
                current[j] = '1';
                if (!query(i, current)) {
                    current[j] = '0';
                } else {
                    max_num |= 1 << j;
                }
            }
        }
    }

    cout << "0 " << max_num << endl;

    return 0;
}