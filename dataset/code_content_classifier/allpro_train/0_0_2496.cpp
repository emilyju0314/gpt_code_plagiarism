#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    
    bool canReach = true;
    for (int i = 0; i < N; i++) {
        if (p[i] == i+1) {
            continue;
        }
        if (i+2 < N && p[i] == i+2 && p[i+1] == i+1) {
            int temp = p[i];
            p[i] = p[i+1];
            p[i+1] = p[i+2];
            p[i+2] = temp;
        } else {
            canReach = false;
            break;
        }
    }
    
    if (canReach) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}