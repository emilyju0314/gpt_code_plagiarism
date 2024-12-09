#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string guess;
        cin >> guess;
        
        // Izzy's strategy: always guess the opposite of the most common guess among other participants
        int count0 = 0, count1 = 0;

        for (char c : guess) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }
        }

        int izzy_guess;
        if (count0 > count1) {
            izzy_guess = 1;
        } else {
            izzy_guess = 0;
        }

        cout << izzy_guess << endl;
        
        int actual_outcome;
        cin >> actual_outcome;
    }

    return 0;
}