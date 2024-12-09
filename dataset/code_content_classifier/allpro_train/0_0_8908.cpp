#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidID(string id) {
    int sum = 0;
    for (int i = 0; i < id.size(); i++) {
        if (id[i] == '*') continue;
        int digit = id[i] - '0';
        if (i % 2 == 0) {
            digit *= 2;
            if (digit >= 10) {
                sum += 1 + digit % 10;
            } else {
                sum += digit;
            }
        } else {
            sum += digit;
        }
    }
    return sum % 10 == 0;
}

void generateIDs(string id, vector<int>& candidates, int index, int& count) {
    if (index == id.size()) {
        if (isValidID(id)) {
            count++;
        }
        return;
    }
    if (id[index] == '*') {
        for (int digit : candidates) {
            id[index] = digit + '0';
            generateIDs(id, candidates, index + 1, count);
            id[index] = '*';
        }
    } else {
        generateIDs(id, candidates, index + 1, count);
    }
}

int main() {
    int n, m;
    string id;
    cin >> n >> id >> m;
    vector<int> candidates(m);
    for (int i = 0; i < m; i++) {
        cin >> candidates[i];
    }
    
    int count = 0;
    generateIDs(id, candidates, 0, count);
    
    cout << count << endl;
    
    return 0;
}