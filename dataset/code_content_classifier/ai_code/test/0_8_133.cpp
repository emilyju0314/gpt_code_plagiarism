#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> bigrams(n-2);
        for (int j = 0; j < n-2; j++) {
            cin >> bigrams[j];
        }

        string word;
        for (int j = 0; j < n-2; j++) {
            if (bigrams[j] == bigrams[j+1]) {
                if (j == 0) {
                    word += 'a';
                } else {
                    word += (word[j-1] == 'a' ? 'b' : 'a');
                }
            } else {
                if (word[j-1] == word[j-2]) {
                    word += (word[j-1] == 'a' ? 'b' : 'a');
                } else {
                    word += word[j-1];
                }
            }
        }

        if (word[n-4] == word[n-3]) {
            word += (word[n-5] == 'a' ? 'b' : 'a');
        } else {
            word += word[n-3];
        }

        cout << word << endl;
    }

    return 0;
}