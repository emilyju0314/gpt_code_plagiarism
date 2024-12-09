#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    cin >> m;

    while(m--) {
        string train;
        cin >> train;

        int n = train.size();
        int total = 0;

        for(int i = 1; i <= n - 1; i++) {
            int j = n - i;
            if(i < j) {
                total += 3 * i * j;
            } else {
                total += i * j;
            }
        }

        cout << total << endl;
    }

    return 0;
}