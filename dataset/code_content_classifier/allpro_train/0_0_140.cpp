#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<string, int> twoGrams;
    for (int i = 0; i < n - 1; i++) {
        string twoGram = s.substr(i, 2);
        twoGrams[twoGram]++;
    }

    int maxCount = 0;
    string maxTwoGram;
    for (auto it : twoGrams) {
        if (it.second > maxCount) {
            maxCount = it.second;
            maxTwoGram = it.first;
        }
    }

    cout << maxTwoGram << endl;

    return 0;
}