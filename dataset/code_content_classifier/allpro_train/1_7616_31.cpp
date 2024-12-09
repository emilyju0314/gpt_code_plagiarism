#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int ans = 0;
    while(n > 0){
        n /= 2;
        ++ ans;
    }
    cout << ans << endl;

    return 0;
}