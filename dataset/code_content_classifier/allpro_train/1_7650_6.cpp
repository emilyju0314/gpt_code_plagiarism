#include <bits/stdc++.h>
std::map<int, std::list<int> > map;
std::map<int, std::list<int> >::iterator it;
short n, k;
int i;
std::list<int> in;
int main() {
  scanf("%hd %hd", &n, &k);
  while (n--) {
    scanf("%d", &i);
    if (!map.count(i)) {
      in.clear();
      in.push_back(i);
      map[i] = in;
    }
    for (it = map.begin(); map.size() < k && it != map.end(); ++it)
      if (it->second.back() != i && !map.count(it->first + i)) {
        in = it->second;
        in.push_back(i);
        map[it->first + i] = in;
      }
  }
  for (it = map.begin(); k-- && it != map.end(); ++it) {
    printf("%lu", it->second.size());
    while (!it->second.empty()) {
      printf(" %d", it->second.front());
      it->second.pop_front();
    }
    puts("");
  }
  return 0;
}
