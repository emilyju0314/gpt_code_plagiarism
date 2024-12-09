#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> reviewers(n);
        for(int i = 0; i < n; i++) {
            cin >> reviewers[i];
        }

        int upvotes = 0;
        int upvotes_server1 = 0;
        int upvotes_server2 = 0;

        for(int i = 0; i < n; i++) {
            if(reviewers[i] == 1) {
                upvotes++;
                if(i % 2 == 0) {
                    upvotes_server1++;
                } else {
                    upvotes_server2++;
                }
            } else if(reviewers[i] == 2) {
                if(i % 2 == 0) {
                    upvotes_server2++;
                } else {
                    upvotes_server1++;
                }
            } else {
                if(upvotes_server1 == upvotes_server2) {
                    upvotes++;
                    if(i % 2 == 0) {
                        upvotes_server1++;
                    } else {
                        upvotes_server2++;
                    }
                } else if(upvotes_server1 < upvotes_server2) {
                    upvotes++;
                    upvotes_server1++;
                } else {
                    upvotes++;
                    upvotes_server2++;
                }
            }
        }

        cout << upvotes << endl;
    }

    return 0;
}