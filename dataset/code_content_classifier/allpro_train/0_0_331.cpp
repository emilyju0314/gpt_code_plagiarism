#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getDegreeOfKinship(const string& input) {
    map<string, int> relations = {
        {"father", 1},
        {"mother", 1},
        {"son", 1},
        {"daughter", 1},
        {"husband", 0},
        {"wife", 0},
        {"brother", 1},
        {"sister", 1},
        {"grandfather", 1},
        {"grandmother", 1},
        {"grandson", 1},
        {"granddaughter", 1},
        {"uncle", 1},
        {"aunt", 1},
        {"nephew", 1},
        {"niece", 1}
    };

    istringstream iss(input);
    string token;
    vector<string> relationships;

    while (iss >> token) {
        if (token != "is" && token != "A's" && token != "C's") {
            relationships.push_back(token);
        }
    }

    int maxDegrees = 0;
    int minDegrees = 0;

    for (int i = 0; i < relationships.size(); i++) {
        string relation = relationships[i];
        minDegrees++;
        maxDegrees = max(maxDegrees, minDegrees);

        if (i+1 < relationships.size()) {
            if (relations[relation] == 1) {
                minDegrees++;
            } else {
                minDegrees = 0;
            }
        }
    }

    return minDegrees - 1;
}

int main() {
    int datasets;
    cin >> datasets;
    cin.ignore();

    while (datasets--) {
        string input;
        getline(cin, input);

        int minDegrees = getDegreeOfKinship(input);
        
        string temp = input;
        reverse(temp.begin(), temp.end());
        int tempLength = temp.find("A'");
        int maxDegrees = temp.size() - tempLength - 3;

        cout << maxDegrees << " " << minDegrees << endl;
    }

    return 0;
}