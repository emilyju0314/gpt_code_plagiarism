#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findStringOfBeads(int n, long long k) {
    // Generate all possible strings of beads
    vector<string> strings;
    for(int i = 0; i < (1 << n); i++) {
        string s;
        for(int j = 0; j < n; j++) {
            if((i & (1 << j)) == 0)
                s += '0';
            else
                s += '1';
        }
        strings.push_back(s);
    }

    // Divide the strings into heaps
    vector<vector<string>> heaps;
    for(int i = 0; i < strings.size(); i++) {
        bool placed = false;
        for(int j = 0; j < heaps.size(); j++) {
            if(heaps[j][0] == strings[i] || heaps[j][1] == strings[i]) {
                heaps[j].push_back(strings[i]);
                placed = true;
                break;
            }
        }
        if(!placed) {
            vector<string> newHeap = {strings[i], strings[i]};
            heaps.push_back(newHeap);
        }
    }

    // Choose the minimum string in each heap
    vector<string> minStrings;
    for(int i = 0; i < heaps.size(); i++) {
        string minStr = heaps[i][0];
        for(int j = 1; j < heaps[i].size(); j++) {
            if(heaps[i][j] < minStr)
            minStr = heaps[i][j];
        }
        minStrings.push_back(minStr);
    }

    // Sort the remaining strings
    sort(minStrings.begin(), minStrings.end());

    // Output the k-th string
    if(k > minStrings.size()) {
        return "-1";
    } else {
        return minStrings[k-1];
    }
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    string result = findStringOfBeads(n, k);
    cout << result << endl;

    return 0;
}