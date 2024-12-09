#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> bookRequests(n);
    for(int i = 0; i < n; i++) {
        cin >> bookRequests[i];
    }
    
    vector<int> bookCosts(n);
    for(int i = 0; i < n; i++) {
        cin >> bookCosts[i];
    }
    
    int cost = 0;
    vector<int> neededBooks(n, 0);
    for(int i = 0; i < n; i++) {
        neededBooks[bookRequests[i]-1]++;
        if(neededBooks[bookRequests[i]-1] > k) {
            int minCost = INT_MAX;
            int minIndex = -1;
            for(int j = 0; j < n; j++) {
                if(neededBooks[j] > k) {
                    if(bookCosts[j] < minCost) {
                        minCost = bookCosts[j];
                        minIndex = j;
                    }
                }
            }
            if(minIndex != -1) {
                neededBooks[minIndex]--;
                cost += minCost;
                neededBooks[bookRequests[i]-1]++;
            }
        }
    }
    
    cout << cost << endl;
    
    return 0;
}