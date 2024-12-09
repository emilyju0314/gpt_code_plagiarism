#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr1(n);
    vector<int> arr2(n);
    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pq.push(arr1[i] + arr2[j]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }

    long long sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << endl;
    
    return 0;
}