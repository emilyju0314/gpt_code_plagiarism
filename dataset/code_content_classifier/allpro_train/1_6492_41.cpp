#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    ll n, v[100010];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mn = 1;
    for (int i = 0; i < n - 1; i++) {
        mn += (v[i] >= v[i + 1]);
    }
    cout << mn << endl << n << endl;

}
