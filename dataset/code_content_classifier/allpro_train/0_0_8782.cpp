#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;

    int washFinish[n1];
    int dryFinish[n2];
    
    fill(washFinish, washFinish + n1, 0);
    fill(dryFinish, dryFinish + n2, 0);

    int minTime = 0;
    for (int i = 0; i < k; i++) {
        int nextWash = *min_element(washFinish, washFinish + n1);
        washFinish[nextWash % n1] += t1;
        
        int nextDry = *min_element(dryFinish, dryFinish + n2);
        nextDry = max(nextDry, washFinish[nextWash % n1]);
        dryFinish[nextDry % n2] = nextDry + t2;
        
        int nextFold = *min_element(dryFinish, dryFinish + n2);
        minTime = max(minTime, nextFold + t3);
    }
    
    cout << minTime << endl;
    
    return 0;
}