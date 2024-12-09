#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        vector<int> subsegment;
        
        for (int j = i; j < n; j++) {
            subsegment.push_back(a[j]);
            sort(subsegment.begin(), subsegment.end());

            int diffs = 0;
            for (int p = 1; p < subsegment.size(); p++) {
                if (subsegment[p] - subsegment[p-1] != d) {
                    diffs++;
                }
            }

            if (diffs <= k && subsegment.size() > maxLength) {
                l = i + 1;
                r = j + 1;
                maxLength = subsegment.size();
            }
        }
    }

    cout << l << " " << r << endl;

    return 0;
}