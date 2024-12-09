#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stickers(n);
    for(int i = 0; i < n; i++) {
        cin >> stickers[i];
    }

    int petyaScore = 0;
    int genaScore = 0;

    int left = 0, right = n - 1;

    while(left <= right) {
        if(stickers[left] < stickers[right]) {
            petyaScore += stickers[right];
            right--;
        } else {
            petyaScore += stickers[left];
            left++;
        }

        if(left <= right) {
            if(stickers[left] < stickers[right]) {
                genaScore += stickers[right];
                right--;
            } else {
                genaScore += stickers[left];
                left++;
            }
        }
    }

    int result = petyaScore - genaScore;

    cout << result << endl;

    return 0;
}