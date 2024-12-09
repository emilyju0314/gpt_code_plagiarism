#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string num;
    cin >> num;

    for (int i = 0; i < k; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (num[j] == '4' && num[j + 1] == '7') {
                found = true;
                if (j % 2 == 0) {
                    num[j] = '4';
                    num[j + 1] = '4';
                } else {
                    num[j] = '7';
                    num[j + 1] = '7';
                }
                break;
            }
        }
        if (!found) {
            break;
        }
    }

    cout << num << endl;

    return 0;
}