#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    for(int i=0; i<n; i++) {
        cin >> B[i];
    }

    vector<pair<int, int>> summedA(n);
    vector<pair<int, int>> summedB(n);

    for(int i=0; i<n; i++) {
        summedA[i] = {A[i], i+1};
        summedB[i] = {B[i], i+1};
    }

    sort(summedA.begin(), summedA.end(), greater<pair<int, int>>());
    sort(summedB.begin(), summedB.end(), greater<pair<int, int>>());

    vector<int> result;

    int i = 0, j = 0;
    long long sumA = 0, sumB = 0;

    while(i<n && j<n) {
        if(2*summedA[i].first >= sumA + summedA[i].first && 2*summedB[j].first >= sumB + summedB[j].first) {
            result.push_back(summedA[i].second);
            sumA += summedA[i].first;
            sumB += summedB[j].first;
            i++;
            j++;
        } else {
            if(2*summedA[i].first < 2*summedB[j].first) {
                sumB += summedB[j].first;
                j++;
            } else {
                sumA += summedA[i].first;
                i++;
            }
        }
    }

    cout << result.size() << endl;
    for(int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}