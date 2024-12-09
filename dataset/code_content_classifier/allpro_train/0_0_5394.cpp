#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int maxPoints = -1;

    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            string first = s.substr(0, i);
            string second = s.substr(i, j - i);
            string third = s.substr(j, n - j);

            if((first[0] != '0' || first.size() == 1) && stoi(first) <= 1000000
               && (second[0] != '0' || second.size() == 1) && stoi(second) <= 1000000
               && (third[0] != '0' || third.size() == 1) && stoi(third) <= 1000000) {
                maxPoints = max(maxPoints, stoi(first) + stoi(second) + stoi(third));
            }
        }
    }

    cout << maxPoints << endl;

    return 0;
}