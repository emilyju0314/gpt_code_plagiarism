#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(p[i] < l[i]) {
            int diff = l[i] - p[i];
            if(i == 0) {
                p[i] += diff;
                p[i+1] += 2 * diff;
                count++;
            } else if(i == n-1) {
                p[i] += diff;
                p[i-1] += 2 * diff;
                count++;
            } else {
                int inc = diff;
                p[i] += diff;
                inc *= 2;
                p[i-1] += inc;
                p[i+1] += inc;
                count++;
            }
        }

        if(p[i] < l[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << count << endl;
    
    return 0;
}