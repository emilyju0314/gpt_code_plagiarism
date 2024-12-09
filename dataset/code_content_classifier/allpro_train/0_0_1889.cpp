#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> t(N);
    for(int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int classes_attended = 0;
    for(int i = 0; i < N; i++) {
        if(t[i] >= A && t[i] <= B) {
            classes_attended++;
        }
    }

    cout << classes_attended << endl;

    return 0;
}