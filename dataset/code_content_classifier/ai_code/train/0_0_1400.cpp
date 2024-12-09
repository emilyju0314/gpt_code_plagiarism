#include <iostream>
#include <string>

using namespace std;

int main() {
    long long k;
    cin >> k;

    string sequence = "";
    long long num = 1;
    while (sequence.size() < k) {
        sequence += to_string(num);
        num++;
    }

    cout << sequence[k-1] << endl;

    return 0;
}