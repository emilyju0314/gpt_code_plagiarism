#include <iostream>
#include <vector>

using namespace std;

void findSequences(int n, string compResults) {
    vector<int> minSeq, maxSeq;
    for(int i = 1; i <= n; i++) {
        minSeq.push_back(i);
        maxSeq.push_back(i);
    }

    // For '<', swap adjacent elements to minimize LIS
    for(int i = 0; i < n-1; i++) {
        if(compResults[i] == '<') {
            swap(minSeq[i], minSeq[i+1]);
        }
    }

    // For '>', reverse part of the sequence to maximize LIS
    int start = 0;
    for(int i = 0; i < n-1; i++) {
        if(compResults[i] == '>') {
            reverse(maxSeq.begin() + start, maxSeq.begin() + i + 2);
            start = i + 1;
        }
    }

    // Print minSeq and maxSeq
    for(int i = 0; i < n; i++) {
        cout << minSeq[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << maxSeq[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        string compResults;
        cin >> n >> compResults;

        findSequences(n, compResults);
    }

    return 0;
}