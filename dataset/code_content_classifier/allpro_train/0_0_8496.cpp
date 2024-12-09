#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> questions(k);
    for(int i=0; i<k; i++) {
        cin >> questions[i];
    }

    long long count = n;
    for(int i=1; i<k; i++) {
        if(questions[i] != questions[i-1]) {
            int diff = abs(questions[i] - questions[i-1]);
            count += (diff - 1);
        }
    }

    cout << count << endl;

    return 0;
}