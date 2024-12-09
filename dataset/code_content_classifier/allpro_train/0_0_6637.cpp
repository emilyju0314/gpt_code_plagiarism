#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1, 0);
    vector<int> childCount(n + 1, 0);

    for(int i = 2; i <= n; i++) {
        cin >> parent[i];
        childCount[parent[i]]++;
    }

    bool isSpruce = true;

    for(int i = 1; i <= n; i++) {
        if(childCount[i] > 0 && childCount[i] < 3) {
            isSpruce = false;
            break;
        }
    }

    if(isSpruce) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}