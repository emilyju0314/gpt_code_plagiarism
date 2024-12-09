#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    int sum = 0;
    int count_zeros = 0;

    for(int i = 0; i < n; i++) {
        cin >> cards[i];
        sum += cards[i];
        if(cards[i] == 0) {
            count_zeros++;
        }
    }

    if(count_zeros == 0) {
        cout << "-1" << endl;
    } else if(sum % 3 != 0) {
        cout << "0" << endl;
    } else {
        sort(cards.rbegin(), cards.rend());

        string result = "";
        for(int card : cards) {
            result += to_string(card);
        }

        cout << result << endl;
    }

    return 0;
}