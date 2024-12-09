#include <iostream>
#include <set>

using namespace std;

int main() {

    int N, L, a[1000000];

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    //solve
    multiset<int> ms;

    for (int i = 0; i < L; i++) {
        ms.insert(a[i]);
    }

    cout << *ms.begin();

    for (int i = L; i < N; i++) {
        ms.insert(a[i]);
        ms.erase(ms.find(a[i - L]));
        cout << ' ' << *ms.begin();
    }

    cout << endl;
}
