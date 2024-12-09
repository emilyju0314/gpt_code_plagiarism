#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string artifact;
    cin >> artifact;

    int n;
    cin >> n;

    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> costs(10);
    for (int i = 0; i < 10; i++) {
        cin >> costs[i];
    }

    int maxCost = 0;
    for (int i = 0; i <= 9; i++) {
        string temp = artifact;
        for (char &c : temp) {
            if (c == '?') {
                c = i + '0';
            }
        }

        int sum = 0;
        for (int j = 0; j < n; j++) {
            string newNum = temp;
            newNum += numbers[j];
            for (char digit : newNum) {
                sum += costs[digit - '0'];
            }
        }

        maxCost = max(maxCost, sum);
    }

    cout << maxCost << endl;

    return 0;
}