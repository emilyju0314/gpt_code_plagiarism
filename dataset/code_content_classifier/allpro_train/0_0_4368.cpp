#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> pieces;
    int luckyTickets = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        int rem = num % 3;
        if (rem == 0) {
            luckyTickets++;
        } else {
            if (pieces[3 - rem] > 0) {
                pieces[3 - rem]--;
                luckyTickets++;
            } else {
                pieces[rem]++;
            }
        }
    }

    cout << luckyTickets << endl;

    return 0;
}