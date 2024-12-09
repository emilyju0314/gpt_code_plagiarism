#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> count(4, 0);
    string line;

    while (getline(cin, line)) {
        int commaPos = line.find(",");
        int attendance = stoi(line.substr(0, commaPos));
        string bloodType = line.substr(commaPos + 1);

        if (bloodType == "A") {
            count[0]++;
        } else if (bloodType == "B") {
            count[1]++;
        } else if (bloodType == "AB") {
            count[2]++;
        } else if (bloodType == "O") {
            count[3]++;
        }
    }

    cout << count[0] << endl;
    cout << count[1] << endl;
    cout << count[2] << endl;
    cout << count[3] << endl;

    return 0;
}