#include <iostream>
#include <vector>

using namespace std;

bool isShichiGoSan(int n) {
    string str = to_string(n);
    vector<int> count(3, 0); // count of 7, 5, 3

    for(char c : str) {
        if (c == '7') count[0]++;
        else if (c == '5') count[1]++;
        else if (c == '3') count[2]++;
        else return false; // if any other digit appears, return false
    }

    return count[0] > 0 && count[1] > 0 && count[2] > 0;
}

int countShichiGoSan(int n) {
    int count = 0;

    for(int i = 1; i <= n; i++) {
        if (isShichiGoSan(i)) count++;
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    cout << countShichiGoSan(N) << endl;

    return 0;
}