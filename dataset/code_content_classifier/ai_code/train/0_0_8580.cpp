#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> doors(n);
    for(int i = 0; i < n; i++) {
        cin >> doors[i];
    }

    int leftCount = 0, rightCount = 0;
    int k = 0;

    for(int i = 0; i < n; i++) {
        if(doors[i] == 0) {
            leftCount++;
        } else {
            rightCount++;
        }

        if(leftCount > 0 && rightCount > 0) {
            k = i + 1;
            break;
        }
    }

    cout << k << endl;

    return 0;
}