#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long crosses = 4*(long long)n;
        crosses += n/2 * n;
        cout << crosses << endl;
    }

    return 0;
}