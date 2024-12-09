#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    int min_mistakes = n;
    string seq_with_min_mistakes;

    for(int i=0; i<=n; i++) {
        int mistakes = 0;
        string sequence = "T";
        int a = 0, b = 1;
        int j = 1; // index of next operation
        while(j < n) {
            if(j % 2 == 1) {
                a = a + b; // T operation
                if(a == r) {
                    mistakes++;
                }
                sequence += "T";
            } else {
                b = a + b; // B operation
                if(b == r) {
                    mistakes++;
                }
                sequence += "B";
            }
            j++;
        }

        if(a == r || b == r) {
            if(mistakes < min_mistakes) {
                min_mistakes = mistakes;
                seq_with_min_mistakes = sequence;
            }
        }
    }

    if(min_mistakes == n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_mistakes << endl;
        cout << seq_with_min_mistakes << endl;
    }

    return 0;
}