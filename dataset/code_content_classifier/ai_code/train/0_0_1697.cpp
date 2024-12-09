#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, string> firstOption;
    unordered_map<string, string> secondOption;

    for(int i = 0; i < n; i++) {
        string teamName, cityName;
        cin >> teamName >> cityName;

        string shortNameFirst = teamName.substr(0, 3);
        string shortNameSecond = teamName.substr(0, 2) + cityName[0];

        if(firstOption.find(shortNameFirst) != firstOption.end()) {
            if(firstOption[shortNameFirst] == shortNameSecond) {
                cout << "NO" << endl;
                return 0;
            } else {
                secondOption[shortNameSecond] = shortNameSecond;
            }
        } else {
            firstOption[shortNameFirst] = shortNameFirst;
        }
        
        cout << "YES" << endl;
        cout << ((secondOption.find(shortNameSecond) != secondOption.end()) ? shortNameSecond : shortNameFirst) << endl;
    }

    return 0;
}