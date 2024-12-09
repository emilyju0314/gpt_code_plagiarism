#include <iostream>
#include <vector>
using namespace std;

string balanceWeights(int weight) {
    string result = "";
    while (weight != 0) {
        if (weight % 3 == 1) {
            result = "+1" + result;
            weight = (weight - 1) / 3;
        } else if (weight % 3 == 2) {
            result = "-1" + result;
            weight = (weight + 1) / 3;
        } else {
            result = "0" + result;
            weight = weight / 3;
        }
    }
    return result;
}

int main() {
    int weight;
    cin >> weight;
    cout << balanceWeights(weight) << endl;
    return 0;
}