#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, b, a;
    cin >> n >> b >> a;

    vector<int> sunlight(n);
    for(int i = 0; i < n; i++) {
        cin >> sunlight[i];
    }

    int segments = 0;
    for(int i = 0; i < n; i++) {
        if(b == 0 && a == 0) {
            break;
        }

        if(sunlight[i] == 0) {
            if(a > 0) {
                a--;
            } else {
                b--;
            }
        } else {
            if(b > 0 && a < a) {
                a++;
                b--;
            } else if(a > 0) {
                a--;
            } else {
                b--;
            }
        }

        segments++;
    }

    cout << segments << endl;
    
    return 0;
}