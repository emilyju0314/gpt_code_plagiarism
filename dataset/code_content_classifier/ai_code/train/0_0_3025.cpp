#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ans;
        int x;
        cin >> ans >> x;
        
        if (ans == 'y' && x < 7) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}