#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int count = 0;
    for(int i = a+1; i <= n-b; i++) {
        count++;
    }

    cout << count << endl;

    return 0;
}