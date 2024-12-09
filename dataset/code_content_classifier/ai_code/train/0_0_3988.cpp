#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int cost = 0;
    int flipCost = 0;
    int swapCost = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cost++;
            if(i < n-1 && a[i+1] != b[i+1] && a[i] != a[i+1]) {
                swapCost++;
                i++;
            } else {
                flipCost++;
            }
        }
    }

    cout << cost - min(flipCost, swapCost) << endl;

    return 0;
}