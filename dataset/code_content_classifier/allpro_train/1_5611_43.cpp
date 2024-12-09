#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector <tuple<int, int, bool>> red, blue;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    red.push_back(tuple<int, int, bool> (y, x, false));
  }
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    blue.push_back(tuple<int, int, bool> (x, y, false));
  }
  
  sort(red.rbegin(), red.rend());
  sort(blue.begin(), blue.end());
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(   get<1>(red[j]) < get<0>(blue[i])
	 && get<0>(red[j]) < get<1>(blue[i])
	    && !get<2>(red[j])) {
	red[j] = make_tuple(get<0>(red[j]), get<1>(red[j]), true);
	ans++;
	break;
      }
    }
  }

  cout << ans << endl;
}