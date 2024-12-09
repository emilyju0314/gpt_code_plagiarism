#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    int currVal = a[left], currCount = 0;
    int totalMoves = 0;

    while(right >= left && currCount < k) {
        int leftMoves = left, rightMoves = n - 1 - right;
        if(leftMoves < rightMoves) {
            int diff = a[left+1] - a[left];
            totalMoves += currCount * leftMoves;
            if(totalMoves >= k) {
                break;
            }
            if(diff * leftMoves <= k - totalMoves) {
                totalMoves += diff * leftMoves;
                left++;
                currVal = a[left];
            } else {
                totalMoves += (k - totalMoves) / leftMoves;
            }
        } else {
            int diff = a[right] - a[right-1];
            totalMoves += currCount * rightMoves;
            if(totalMoves >= k) {
                break;
            }
            if(diff * rightMoves <= k - totalMoves) {
                totalMoves += diff * rightMoves;
                right--;
                currVal = a[right];
            } else {
                totalMoves += (k - totalMoves) / rightMoves;
            }
        }
        while(left < n && a[left] == currVal) {
            currCount++;
            left++;
        }
        while(right >= 0 && a[right] == currVal) {
            currCount++;
            right--;
        }
    }

    cout << totalMoves << endl;

    return 0;
}