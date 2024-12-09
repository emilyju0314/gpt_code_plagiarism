#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string luckyString = "";
    for(int i = 0; i < n; i++) {
        luckyString += 'a' + i % 3;
    }

    cout << luckyString << endl;

    return 0;
}