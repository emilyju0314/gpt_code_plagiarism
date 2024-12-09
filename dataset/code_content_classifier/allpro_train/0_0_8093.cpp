#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int m = strings[0].length(); // length of each string

    double expected_questions = 0.0;
    for(int i = 0; i < m; i++) {
        int distinct_chars = 0;
        for(int j = 0; j < n; j++) {
            bool found = false;
            for(int k = 0; k < j; k++) {
                if(strings[j][i] == strings[k][i]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                distinct_chars++;
            }
        }
        expected_questions += 1.0 / distinct_chars;
    }

    cout.precision(9);
    cout << fixed << expected_questions << endl;

    return 0;
}