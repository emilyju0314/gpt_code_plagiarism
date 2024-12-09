#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, x, a, b;
        cin >> n >> x >> a >> b;

        int distance;
        if(abs(a - b) + x >= n - 1){
            distance = n - 1;
        } else {
            distance = abs(a - b) + x;
        }

        cout << distance << endl;
    }

    return 0;
}