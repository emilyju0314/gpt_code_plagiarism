#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

typedef struct button{
  pii s, e;
  string link;
}button;

typedef struct window{
  string name;
  vector<button> b;
}window;

bool range(pii s, pii e, int w, int h){
  return s.first <= w and w <= e.first and
    s.second <= h and h <= e.second;
}

int main(){
  int n, m, l, W, H;
  while(std::cin >> n, n){
    vector<window> vw(n);
    map<string, int> next;
    std::cin >> W >> H;
    for (int i = 0; i < n; i++) {
      std::cin >> vw[i].name >> l;
      next[vw[i].name] = i;
      for (int j = 0; j < l; j++) {
        button tmp;
        std::cin >> tmp.s.first >> tmp.s.second
                 >> tmp.e.first >> tmp.e.second >> tmp.link;
        vw[i].b.push_back(tmp);
      }
    }
    std::cin >> m;
    string s;
    vector<string> buffer;
    buffer.push_back(vw[0].name);
    int pos = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> s;
      if(s == "click"){
        int w, h;
        std::cin >> w >> h;
        int win = next[buffer[pos]];
        for (int j = 0; j < vw[win].b.size(); j++) {
          if(range(vw[win].b[j].s, vw[win].b[j].e,
                   w, h)){
            if(pos + 1 < buffer.size())
              buffer.erase(buffer.begin() + pos + 1, buffer.end());
            buffer.push_back(vw[win].b[j].link);
            pos++;
          }
        }
      }else if(s == "show"){
        std::cout << vw[next[buffer[pos]]].name << std::endl;
      }else if(s == "back"){
        pos = max(0, (int)(pos - 1));
      }else if(s == "forward"){
        pos = min((int)(buffer.size() - 1), pos + 1);
      }
    }
  }
  return 0;
}