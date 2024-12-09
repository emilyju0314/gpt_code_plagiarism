#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> bigrams(n-2);
        for (int i = 0; i < n-2; i++) {
            cin >> bigrams[i];
        }

        string word;
        word += bigrams[0][0];
        
        for (int i = 0; i < n-2; i++) {
            word += bigrams[i][1];
        }
        
        word += bigrams.back()[0];

        cout << word << endl;
    }

    return 0;
}