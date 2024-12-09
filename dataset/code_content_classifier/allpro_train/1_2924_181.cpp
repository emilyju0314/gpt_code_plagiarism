#include <iostream>
using namespace std;
int main() {
int N;
long ans = 1;
cin >> N;
for (int i = 1; i <= N; ++i) ans = ans * i % 1000000007;
cout << ans << endl;
}