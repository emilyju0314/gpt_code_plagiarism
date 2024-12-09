#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;
    
        vector<int> count(26, 0);
        for(char c : S) {
            count[c - 'a']++;
        }

        vector<int> order = {0, 1, 2}; // order of characters a, b, c
        string newS = "";

        do {
            string currS = "";
            for(int i = 0; i < 3; i++) {
                char currChar = 'a' + order[i];
                int currCount = count[currChar - 'a'];
                currS += string(currCount, currChar);
            }

            bool isSubsequence = false;
            int idxT = 0;
            for(char c : currS) {
                if (c == T[idxT]) {
                    idxT++;
                    if (idxT == 3) {
                        isSubsequence = true;
                        break;
                    }
                }
            }

            if (!isSubsequence) {
                if (newS == "" || currS < newS) {
                    newS = currS;
                }
            }
        } while(next_permutation(order.begin(), order.end()));

        cout << newS << endl;
     }

    return 0;
}