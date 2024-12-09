#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, vector<int>>> info(n);

    for(int i=0; i<n; i++) {
        string ti;
        int ki;
        cin >> ti >> ki;
        vector<int> positions(ki);
        for(int j=0; j<ki; j++) {
            cin >> positions[j];
        }
        info[i] = make_pair(ti, positions);
    }

    string result = "";
    int currentPos = 1;
    for(auto& it : info) {
        string ti = it.first;
        vector<int> positions = it.second;

        while(currentPos < positions[0]) {
            result += "a";
            currentPos++;
        }

        for(int j=0; j<ti.length(); j++) {
            result += ti[j];
            currentPos++;
        }

        for(int j=1; j<positions.size(); j++) {
            while(currentPos < positions[j]) {
                result += "a";
                currentPos++;
            }
            for(int k=0; k<ti.length(); k++) {
                result += ti[k];
                currentPos++;
            }
        }
    }

    while(result.length() < currentPos) {
        result += "a";
    }

    cout << result << endl;

    return 0;
}