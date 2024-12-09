#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> requests(n);
    for(int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    vector<int> books(k+1, 0);
    int cost = 0;
    int bought = 0;
    for(int i = 0; i < n; i++) {
        if(books[requests[i]] == 0) {
            if(bought < k) {
                books[requests[i]] = 1;
                bought++;
            } else {
                int min_idx = 1;
                for(int j = 1; j <= k; j++) {
                    if(books[j] == 0) {
                        min_idx = j;
                        break;
                    }
                    if(i == n-1) {
                        books[j] = 0;
                        min_idx = j;
                        break;
                    }
                    if(k - i < books[j]) {
                        min_idx = j;
                        break;
                    }
                }
                books[min_idx] = 0;
                books[requests[i]] = 1;
                cost++;
            }
        }
    }

    cout << cost << endl;

    return 0;
}